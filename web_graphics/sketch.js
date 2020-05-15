
const key = 'pk.eyJ1Ijoib3JhbmdlbWFtYmEiLCJhIjoiY2sxeTRlM2hxMGpqeTNtczV0cGFzYjk2NCJ9.n000lu-4M59iD3JhniH81w';

var mapImg; // UMN Image generated from myMap
var myMap; // Map from mappa
var imageWidth;
var imageHeight;
let imageX = 250; // Top left position, in pixels, of image
let imageY = 1; // Top left position, in pixels, of image

const updateTime = 1000; // miliseconds
var totalUpdates = 0; // How many times have we called update on the sim
var elapsedTime;
var startTime;

var socket;
var connected;

var busses = [];
var stops = [];
var routes = [];

var numRoutes;
var busTimeOffsetsSliders = [];
var busTimeOffsets = [];

var numTimeStepsSlider;
var numTimeSteps;

var startButton;
var started;

var simInfoYRectPos = 1; // Magic numbers for GUI elements
var simInfoYPos = 15;
var numTimeStepsTextYPos = 50;
var numTimeStepsSliderYPos = 65;
var busTimeOffsetsYInitTextPos = 120;
var busTimeOffsetsYInitPos = 140;
var busTimeOffsetsYOffset = 50;
var runRectYPos = 450;
var runYPos = 465;
var startYPos = 500;

// Data for vis. Matches data_structs.h in C++
function Position(x, y) {
	this.x = x;
	this.y = y;
}
function Bus(id, position, numPasengers, capacity) {
	this.id = id;
	this.position = position;
    this.numPassengers = numPassengers;
    this.capacity = capacity;
}
function Stop(id, position, numPeople) {
	this.id = id;
	this.position = position;
	this.numPeople = numPeople;
}
function Route(id, stopIndices) {
	this.id = id;
	this.stopIndices = stopIndices;
}


function setupSocket() {
    try {	    
	// Handles commands sent up from C++
        socket.onmessage =function got_packet(msg) {
            
            var data = JSON.parse(msg.data);

            if (data.command == "initRoutes") {
                numRoutes = int(data.numRoutes / 2);
                initRouteSliders();
            }
            if (data.command == "updateBusses") {
                
                busses = [];

                for (let i = 0; i < data.busses.length; i++) {
                    id = data.busses[i].id;
                    numPassengers = data.busses[i].numPassengers;
                    capacity = data.busses[i].capacity;
                    
                    x = data.busses[i].position.x;
                    y = data.busses[i].position.y;
                    position = new Position(x, y);

                    busses.push(new Bus(id, position, numPassengers, capacity));
                }
            }
            if (data.command == "updateRoutes") {
                
                routes = [];
                
                for (let i = 0; i < data.routes.length; i++) {
                    id = data.routes[i].id;

                    route_stop_indices = [];

                    for (let j = 0; j < data.routes[i].stops.length; j++) {
                        stop_id = data.routes[i].stops[j].id;
                        
                        let index = stops.findIndex(x => x.id == stop_id);
                        if (index == -1) {
                            numPeople = data.routes[i].stops[j].numPeople;

                            x = data.routes[i].stops[j].position.x;
                            y = data.routes[i].stops[j].position.y;
                            position = new Position(x, y);

                            stops.push(new Stop(stop_id, position, numPeople));

                            route_stop_indices.push(stops.length-1);
                        } else {
                            stops[index].numPeople = data.routes[i].stops[j].numPeople;
                            route_stop_indices.push(index);
                        }
                    }
                    routes.push(new Route(id, route_stop_indices));
                }
            }
        } 
    } catch(exception) {
        alert('<p>Error' + exception);  
    }

    connected = false;

    // Makes sure that our sim doesn't start until we are connected and have necessary info
    socket.onopen = function() {
        connected = true;
        socket.send(JSON.stringify({command: "initRoutes"}));
    }
}





/// * * * * * P5 functions * * * * * ///

function setup() {
    socket = new WebSocket("ws://" + location.hostname+(location.port ? ':'+location.port: ''), "web_server");
    setupSocket();
    
    busses = [];
    stops  = [];
    routes = [];
    
    canvas = createCanvas(windowWidth, windowHeight);

    textSize(12);

    numTimeStepsSlider = createSlider(1, 50, 25, 1);
    numTimeStepsSlider.position(10, numTimeStepsSliderYPos);
    numTimeStepsSlider.style('width', '200px');

    startButton = createButton('Start');
    startButton.position(10, startYPos);
    startButton.style('width', '200px');
    startButton.style('height', '20px');
    startButton.mousePressed(start);    

    // Image/map information
    const options = {
        lat: 44.9765,
        lng: -93.215,
        zoom: 13,
        width: 900,
        height: 600,
        scale: 1,
        pitch: 0,
        style: 'dark-v9',
    };
    imageWidth = options.width;
    imageHeight = options.height;
    const mappa = new Mappa('Mapbox', key);
    myMap = mappa.staticMap(options);
    mapImg = loadImage(myMap.imgUrl);
}

function draw() {
	if (started && connected) {
		update();
    }
    render();
    drawGui();
    drawInfo();
}

function update() {
	// Send down commands to C++
	socket.send(JSON.stringify({command: "getRoutes"}));
	socket.send(JSON.stringify({command: "getBusses"}));

	// Only update every specified timestep
    elapsedTime = millis() - startTime;
    if (elapsedTime > updateTime && totalUpdates <= numTimeSteps) {
        socket.send(JSON.stringify({command: "update"}));
        startTime = millis();
        totalUpdates++;
    }
}

function render() {
    clear();

    image(mapImg, imageX, imageY); 
   
    push();
    stroke(0);
    // Draw Routes
    for (let i = 0; i < routes.length; i++) {
        for (let j = 0; j < routes[i].stopIndices.length-1; j++) {
            x1 = stops[routes[i].stopIndices[j]].position.x;
            y1 = stops[routes[i].stopIndices[j]].position.y;
            var pos1 = myMap.latLngToPixel(x1, y1); // draw on image from lat long
            pos1.x = pos1.x + imageX;
            pos1.y = pos1.y + imageY;

            x2 = stops[routes[i].stopIndices[j+1]].position.x;
            y2 = stops[routes[i].stopIndices[j+1]].position.y;
            var pos2 = myMap.latLngToPixel(x2, y2);
            pos2.x = pos2.x + imageX;
            pos2.y = pos2.y + imageY;

            strokeWeight(4);
            line(pos1.x, pos1.y, pos2.x, pos2.y);
        }
    }
    pop();

    // Draw Stops
    for (let i = 0; i < stops.length; i++) {
        x = stops[i].position.x;
        y = stops[i].position.y;
        var pos = myMap.latLngToPixel(x, y);
        pos.x = pos.x + imageX;
        pos.y = pos.y + imageY;

        fill(255);
        ellipse(pos.x, pos.y, 25, 25);

        push();
        fill(0);
        textAlign(CENTER);
        textSize(14);
        text(stops[i].id, pos.x, pos.y);
        pop();
    }

// Draw Busses
    for (let i = 0; i < busses.length; i++) {
        x = busses[i].position.x;
        y = busses[i].position.y;
        var pos = myMap.latLngToPixel(x, y);

        pos.x = pos.x + imageX;
        pos.y = pos.y + imageY;

        push();
        fill(255, 0, 0, 255);
        rectMode(CENTER);
        rect(pos.x, pos.y, 45, 30, 20);

        textAlign(CENTER, CENTER);
        fill(0);
        textSize(14);
        text(busses[i].id, pos.x, pos.y);
        pop();
    }
}

function drawGui() {
    // GUI rect
    fill(255, 255, 255, 50);
    rect(1, simInfoYRectPos, 205, 27);
    rect(1, runRectYPos, 205, 27);

    fill(0);

    push();
    textSize(16);
    textAlign(CENTER, CENTER);
    text('Sim Info', 102, simInfoYPos);
    text('Run', 102, runYPos);
    pop();

    textAlign(LEFT, CENTER);
    text('Number of time steps to run:  ' + numTimeStepsSlider.value(), 10, numTimeStepsTextYPos);
    for (let i = 0; i < numRoutes; i++) {
        text('Time steps between busses for route ' + i + ': ' +  busTimeOffsetsSliders[i].value(), 10, busTimeOffsetsYInitTextPos + busTimeOffsetsYOffset * i);
    }
}

function start() {
    for (let i = 0; i < busTimeOffsetsSliders.length; i++) {
        busTimeOffsets[i] = busTimeOffsetsSliders[i].value();
    }
    
    numTimeSteps = numTimeStepsSlider.value();
    socket.send(JSON.stringify({command: "start", numTimeSteps: numTimeSteps, timeBetweenBusses: busTimeOffsets}));
    started = true;
    elapsedTime = millis();
    startTime = millis();
}

function initRouteSliders() {
    
    for (let i = 0; i < numRoutes; i++) {
        busTimeOffsetsSliders[i] = createSlider(1, 10, 5, 1);
        busTimeOffsetsSliders[i].position(10, busTimeOffsetsYInitPos + busTimeOffsetsYOffset * i);
        busTimeOffsetsSliders[i].style('width', '200px');
    }
	
}

function drawInfo() {
    // Draw bus info when moused over
    for (let i = 0; i < busses.length; i++) {
        var pos = myMap.latLngToPixel(busses[i].position.x, busses[i].position.y);
        pos.x = pos.x + imageX;
        pos.y = pos.y + imageY;
        
        // If we are over the bus
        if (abs(mouseX - pos.x) < 25 && abs(mouseY - pos.y) < 15) {
            fill(0, 0, 0, 50);
            rect(mouseX - 120, mouseY - 40, 120, 40);
            fill(255);
            text("NumPassengers: " + busses[i].numPassengers, mouseX - 115, mouseY - 30);
            text("Capacity: " + busses[i].capacity, mouseX - 115, mouseY - 15);
            return;
        }
    }
    // draw stop info when moused over
    for (let i = 0; i < stops.length; i++) {
        var pos = myMap.latLngToPixel(stops[i].position.x, stops[i].position.y);
        pos.x = pos.x + imageX; //(windowWidth - imageWidth) / 2;
        pos.y = pos.y + imageY; //(windowHeight - imageHeight) / 2;

        if (abs(mouseX - pos.x) < 13 && abs(mouseY - pos.y) < 13) {
            fill(0, 0, 0, 50);
            rect(mouseX - 120, mouseY - 40, 120, 20);
            fill(255);
            text("People waiting: " + stops[i].numPeople, mouseX - 115, mouseY - 30);
            break;
        }
    }
}
