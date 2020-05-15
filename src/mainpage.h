/*! \mainpage Bus Simulator
 *
 * \section intro_sec Introduction
 *
 * In this project there are two different simulations that can be done. The first one is through
 * configuration simulator which given arguments gives terminal output of the transit
 * simulation. The next simulation, visualization simulator, is a visual representation of the buses
 *  on the route using a web browser.
 *
 * There are multiple classes in Project which be divided into different core
 * functionality of the project for easier understanding
 *
 * Lets look at the files in project/src:
 * The simulator.h is inherited by configuration_simulator which is the simulator for configuration_sim
 *  in project/drivers folder. visualization_simulator_CC.txt is a placeholder for visualization_simulator.cc
 *  located in web directory (/classes/grades/Fall-2019/csci3081/project/web/). This was done due to issues with header “web_interface.h”.
 *
 * The Simulator:
 *  - simulator.h
 *  - configuration_simulator.cc
 *  - visualization_simulator_CC.txt
 *
 * These classes generate the passengers and the
 *
 * Generators and Factory Classes:
 *  - passenger_factory.cc
 *  - passenger_generator.cc
 *  - random_passenger_generator.cc
 *
 * The generator classes allow us to take in a list of probabilities and stops
 * in which we can choose where to populate stops in simulation. The factory
 * class allows the generation of a unique passsenger that has a name,
 * destination and other identifying factors.
 *
 * Core Functionality Classes:
 *  - bus.cc
 *  - route.cc
 *  - stop.cc
 *  - passenger.cc
 *
 * This header holds all the structs needed for visualization simulator to run. First all the
 * necessary data for bus and route in visualization simulator are created and inputted as
 * a struct where the visualization simulator takes these structs and uses the data to update
 * it’s graphics.
 *
 * Setup for Visualization Simulator
 * - data_structs.h
 *
 * Folders/files that are important NOT in project/src:
 *  configuration_sim which initializes configuration_simulator which we can specify
 *  different arguments for
 *  - located in project/drivers/configuration_sim
 *  config folder which holds the txt(s) which specifies the routes and stops that configuration
 *  simulator needs to run. Can specify as an argument when running configuration simulator
 *  executable what config txt ro run.
 *  - located in project/config
 *
 * These are the classes and headers in which the functionality of the simulation will be
 * based on. These classes will allow us to create a simulation of a campus
 * bus at the University of Minnesota or elsewhere.
 *
 * \section body_More More InDepth Look at Functionality Classes:
 * Def: inbound = incoming_route, outbound = outgoing_route
 *
 * Bus.cc: Responsible for the bus in the simulation. When a bus is created
 * it has a name, outgoing routes, ingoing routes, a max capacity for passengers and a
 * speed. The most pertinent function to look in Bus is the Update function. When
 * update is called this is when the bus will check whether or not it is on the
 * outgoing route or on the inbound route. Then it will check if the remaining
 * distance to a stop is 0 or negative. This means that the bus has arrived to the
 * next stop and we can then unload and load passengers at that stop. If the
 * remaining distance is above zero then bus has not arrived at stop yet and it
 * will do nothing. After that we update the time for passengers on the bus and
 * move the bus forward. If the bus goes through both inbound and outbound route
 * then at the last stop the bus will drop off all of its passengers and then
 * be destroyed.
 *
 * Route.cc: Responsible for holding a list of Stops that the bus will go through and
 * distance between each stop in the route. The Route will be cloned in simulator and given
 * to bus to be either inbound or outbound route. The Bus will use the route to look at
 * what stops it needs to go through sequentially. The Route is also responsible for generating
 * passengers at each stop on its route and calling update to each particular stop on its route.
 *
 * Stop.cc: Stop class is responsible for holding the passengers at its stop waiting
 * for bus and calling passengers update so they keep track of how long they are at
 * the stop.
 *
 * Passenger.cc: Passengers when created have a name, a destination they want to
 * to go to and also keep track of how long they wait at a bus and are on a bus.
 * Passengers are created initially at a stop and wait for a bus to come. Once
 * they get on the bus they then ride that bus till their destination where they
 * get off.
 *
 * \section body_More2 Sequence Overview for Configuration Simulator:
 *
 * Configuration Simulator driver is found in project/drivers/configuration_sim
 * When compiled config_sim executable is created which can be run with these arguments
 * ./build/bin/config_sim <txt in configuration folder> <how long sim is run> <start time of first bus>
 *
 * If config sim is not given a specific argument will run the default for the argument. Default
 * for  txt in configuration folder if argument not provided or incorrect will result in sim running
 * config.txt otherwise it will run the txt that you specify located in the project/config folder.
 * The length of sim (how many time steps the simulation will run for)
 * if not given by the arguments or formatted incorrectly is 50 time steps and
 * the default for start time of first bus is 10. Which means at time step of 10 the first bus will
 * be generated. The definition of a time step is where the simulation is updated which we will
 * view later so if simulation is updated 5 times the time step is now 5 (starts at 0).
 *
 * The inbound and outbound routes are
 * created through the config txt and configuration manager. The configuration manager in src
 * takes the routes, stops, etc in config txt (view config.txt for more details on what is included)
 * and creates a list of stops, distances, and probabilities and creates the routes for
 * config sim to plug into Config Simulator (this is configuration_simulator.cc in src) we also
 * input in time step of generation for the first bus. (name of ConfigSimulator is my_sim)
 *
 * After my_sim is given the pointer for routes and first bus time step mysim.Start() function is called.
 * What this does is initialize the simulation inside configuration_simulator.cc using the data
 * given and make sure the simulator is ready to run.
 *
 * Then we go through a for loop from time step of 0 to length of simulation which is specified by
 * arguments or given by default. Inside this loop we call my_sim.Update()
 * In configuration_simulator.cc (in src) when my_sim.Update() is being called
 * first gives what time step it is on then checks if bus needs to be generated on route.
 * It then looks at each Bus and updates it.
 * Bus.Update(): Checks to see if bus is at a particular stop or not.
 * The bus needs to communicate with route to see if distance remaining is 0 or less
 * if so that means it is at a stop and it will get the stop id to see if any Passengers
 * need to be unloaded. Once it does so it then communicates with Stop to get the
 * Passengers that are loaded onto the bus. If not at a stop (i.e remaining distance >0)
 * bus will do nothing. Once these instructions are done in update then Bus needs to
 * update the times for passengers and move according to its speed. Reports are then
 * called to see what changes have occured to buses.
 *
 * If in case bus has traveled across both its inbound and outbound routes then
 * IsTripComplete is set to true where bus unloads all passengers and is destroyed. The
 * Simulator checks to see if this happens and will create a new bus later on to take its place.
 *
 * After that is done then update on routes are called.
 * Route.Update(): Route calls update to generate passengers and if there are then it would
 * update their time to reflect how long they have waited at stop.
 * Then report on Route is called which is done to see what changes have occured in the stop
 * of the routes
 *
 * This cycle repeats until the length of simulation is exceeded. If any arguments were inputted
 * incorrectly the terminal will print out statement of what error has occured after default has run.
 *
 * \section body_More3 Overview of Visualization Simulator
 * Visualization Simulator is very similar to configuration simulator except that the only argument
 * that needs to be provided is the port number. More information on how to run this simulator
 * specified in User Guide.
 *
 * Visualization Simulator (vis_sim executable name)
 * currently uses default config.txt in the config folder. It takes in the
 * routes by using config manager same way as config sim and has a similar format to
 * configuration_simulator.cc. However instead of reporting values when updating Bus or
 * Route it hands the data to visualizer which is shown on an online browser and repeats for
 * length of sim specified in online browser.
 *
 * How is Data given through Visualization Simulator?
 * The data given to the visualizer is in the form of structs (these structs can be seen in
 * data_structs.h). When bus is being updated the struct for bus is updated (UpdateBusData)
 * and the values for the bus is put into bus_data_ struct_. Here the id, number of passengers,
 * capacity, and location (provided through position struct) is updated and then given to
 * the visualizer to interpret and show graphically on the online browser the changes done
 * to the bus.
 *
 * When route is being updated UpdateRouteData() is called which updates the struct for Route
 * that the visualizer uses to check what stops are on each route. When UpdateRouteData()
 * is called the struct is stored in route_data_ and id of stops and location of each stops is
 * stored in the struct which is then later interpreted by the visualizer which shows the stops
 * by circles with numbers inside of it, and the routes outlined by black lines.
 *
 * Regression Testing
 * regression testing is done through new_local_simulator files in src and
 * using my_regression_driver in drivers. This is compiled to test whether
 * or not the output of a test is the same given that all conditions are the
 * the same. To test regression testing check user guide below.
 *
 * \section body_More4 User Guide:
 *
 * HOW TO DOWNLOAD TRANSIT SIMULATOR:
 * 1. Navigate to https://github.umn.edu/umn-csci-3081-f19/repo-hwan0259
 * 2. Locate the Clone Or Download button
 * 3. Copy the https address given by the Clone Or Download button
 * 4. Navigate in terminal to a place you wish to have transit_sim
 * 5. Once you have found the place to settle transit_sim write in terminal
 *	git clone <Paste of https address (from step 3)>
 * 6. Once step 5 has been completed you should see folder repo-hwan0259
 *	in the directory where you ran git clone.
 * 7. If folder found transit_sim has been downloaded if not then follow
 *	steps closely again
 *
 * HOW TO CONFIGURE TRANSIT SIMULATOR:
 * Once you have cloned the repository repo-hwan0259 onto your machine
 * move into the folder and find project
 *  - There are Two Locations to Configure the Transit Simulators
 * 1. Inside of project
 * 	- If inside the folder project, type in “make” on the terminal. Once that has been
 *	done make will call make all in the make file in project/src which creates
 *	config_sim and vis_sim executables all at once in project/bin/build folder.
 *	- If  you want to get rid of the executables then type in “make clean”
 *	this will get rid of the executables and data associated with config_sim
 *	and vis_sim.
 * 2. Inside of project/src
 *	- Once inside project should see src folder navigate inside of src folder and can now
 *	specify whether to run all or run config_sim or vis_sim individually.
 *	- If you want to run all at once can type in “make” in terminal which will create the
 *	executables of config_sim and vis_sim in project/bin/build folder
 *	- If you want to run the simulators individually can type in “make config_sim” in
 *	terminal to make the executable for config_sim in project/build/bin folder.
 *	- Similarly if you run “make vis_sim” in terminal this will create a vis_sim
 *	executable in project/build/bin.
 *
 * HOW TO OPERATE TRANSIT SIMULATOR:
 * Running Vis_Sim *Follow instructions of https://github.umn.edu/umn-csci-3081-f19/csci3081-shared-upstream/blob/support-code/project/README.md to run vis_sim
 *
 * Running config_sim
 * 1. config_sim executable is in folder project/build/bin/
 * 2. run config_sim by staying in project directory and type in terminal
 * ./build/bin/config_sim <a txt in configuration folder> <how long sim is run> <start time of first bus>
 * 3. Default is ./build/bin/config_sim config.txt 50 10
 * 4. If errors are made in config sim then print statements after output
 * will be run
 *
 * HOW TO CREATE CONFIG TEXTS
 * 1. To create your own stops and routes to run with config sim
 *  need to navigate to project/config folder
 * 2. Use base for your config texts from config.txt
 * 3. Specify ROUTE_GENERAL, <name of bus>
 * 4. Then next line should be Stop Name, Long, Lat, Pass Gen Prob
 * 5. Then specify Routes there are only two
 * 6. ROUTE, <name of rotue>
 * 7. Specify Stops with this order
 * STOP, <name of stop>, <long> , <lat>, <pass gen prob>
 * 8. repeat for second stop
 *
 * HOW TO CONFIGURE AND RUN TESTS
 * 1. go to repo-hwan0259/project/tests
 * 2. run “make”
 * 3. go to repo-hwan0259/project
 * 4. run “./build/bin/unittest” and check to see if all tests for transit_sim are passing
 *
 * HOW TO COMPILE REGRESSION TESTS
 * 1. Commented out CONSTPASS in passenger_factory.cc
 * in my final delivery. To get regression testing to
 * work then need to uncomment CONSTPASS this will make
 * all passengers the same.
 * 2. Run make all, or run make my_regression_test in src folder
 * 3. In project run './build/bin/my_regression_test > rtout1'
 * 4. In project run './build/bin/my_regression_test > rtout2'
 * 5. In project cd to /build/bin/ and run 'diff rtout1 rtout2' to see
 * if there are any differences in regression test.
 *
 * HOW TO REPORT ISSUES
 * 1. If you find an error then go to
 * https://github.umn.edu/umn-csci-3081-f19/repo-hwan0259
 * 2. Go to issues and click on the button called make new issue
 * 3. Title your issue and write a description of what is incorrect and label
 * 4. Click submit new issue
 *
 * HOW TO CREATE A NEW BRANCH IN GITHUB
 * Creating a new branch is useful for addressing any issues without
 * changing the main code.
 * 1. git checkout -b fix/<issue in repo here>
 * 2. git push --set-upstream origin fix/<issue specified>
 * 3. git branch is now created
 *
 * HOW TO COMMIT MESSAGES ON BRANCH
 * 1. start the process of committing with
 * git add * (adds all changes that were made)
 * 2. git commit (opens empty message to edit)
 * 3. When you do this you want to add message below
 * hashes and include useful information of what
 * was changed. Follow template like this:
 *
 * fix(files): fix #1 <short description of commit>
 * - Multiple lines of description
 * - Lists all the Important elements that have been changed
 * - eetc.
 *
 * 4. git push --set-upstream origin fix/<issue specified>
 * 5. The push will be looked at by creators and merged accordingly
 *
 * HOW TO CHECK IF YOUR CODE IS STYLE COMPLIANT
 * Need to make sure code is Style compliant before being pushed
 * or else will not be accepted
 * 1. In the repo folder that was cloned locate the /cpplint
 * folder and copy location (can use pwd)
 * 2. To if file is style compliant cd to location
 * 3. ../../../cpplint/cpplint-cse.h --root=.. <file_name>.cc
 * 4. If you want to file check a header file
 *  ../../../cpplint/cpplint-cse.h --root=.. <file_name>.h
 *
 * HOW TO COMPILE DOXYGEN
 * Doxygen generates documentation from the files provided
 * in project
 * 1. navigate to project
 * 2. cd to docs
 * 3. run doxygen Doxyfile
 *
 * USEFUL LINK FOR CREATING UNIT TESTS
 * https://github.umn.edu/umn-csci-3081-f19/repo-hwan0259/tree/master/labs/lab06_google_tests
 */
