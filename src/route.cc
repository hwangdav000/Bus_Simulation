/**
 * @file route.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "./route.h"

//  route constructor
Route::Route(std::string name, Stop ** stops,
  double * distances, int num_stops, PassengerGenerator* pass_g) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }
  name_ = name;
  num_stops_ = num_stops;
  generator_ = pass_g;
  destination_stop_index_ = 0;
  trip_time_ = 0.0;
}

//  clones route
Route * Route::Clone() {
  //  return name, stops, distances, num_stops, pass_g
  //  change stops to ** stops
  //  change distances to * distances
  double * dist_c_ = new double[distances_between_.size()];

  //  iterate through dist_c
  int i = 0;
  for (std::list<double>::const_iterator it = distances_between_.begin();
  it != distances_between_.end(); it++) {
    dist_c_[i] = (*it);
    i++;
  }

  //  iterate through stops
  Stop ** stop_c_ = new Stop *[stops_.size()];
  int j = 0;
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    stop_c_[j] = (*it);
    j++;
  }

  return new Route(name_, stop_c_, dist_c_, num_stops_, generator_);
}

//  generate new passengers
int Route::GenerateNewPassengers() {
  generator_ -> GeneratePassengers();
  return 1;
}

//  generate passengers to stops and then update all
//  stops in route
void Route::Update() {
  GenerateNewPassengers();
  for ( std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Update();
  }
  UpdateRouteData();
}

//  getter for stop
int Route::GetNumStops() const {
  return num_stops_;
}

//  check if at last stop
bool Route::IsAtEnd() const {
  if (destination_stop_index_+1 >= (num_stops_-1)) {
    return true;
  }
  return false;
}

//  Change destination_stop_ to next stop
void Route::NextStop() {
  if (destination_stop_index_ < num_stops_) {
    destination_stop_index_++;
  }
  destination_stop_ = GetDestinationStop();
}

//  get next stop
Stop * Route::GetNextStop() const {
  std::list<Stop *>::const_iterator it = stops_.begin();
  for (int i=0; i < destination_stop_index_; i++) {
    ++it;
  }

  //  at end of route
  if (!(destination_stop_index_ +1 >= num_stops_)) {
    ++it;
  }
  return *it;
}

//  get prev stop
Stop * Route::GetPrevStop() const {
  std::list<Stop *>::const_iterator it = stops_.begin();
  for (int i=0; i < destination_stop_index_; i++) {
    ++it;
  }
  //  edge case for start of route
  if (!(destination_stop_index_ == 0)) {
    --it;
  }
  return *it;
}

//  Get stop at index
Stop * Route::GetDestinationStop() const {
  std::list<Stop *>::const_iterator it = stops_.begin();
  for (int i=0; i < destination_stop_index_; i++) {
    ++it;
  }
  return *it;
}

//  get total route distance
double Route::GetTotalRouteDistance() const {
  double total_ = 0.0;
  std::list<double>::const_iterator it = distances_between_.begin();
  for (int i=0; i < num_stops_-1; i++) {
    total_ = total_ + *it;
    ++it;
  }
  return total_;
}

//  get distance between current stop and next stop
double Route::GetNextStopDistance() const {
  //  end of stop
  if (destination_stop_index_ == (num_stops_-1)) {
    return -1;
  }
  std::list<double>::const_iterator it = distances_between_.begin();
  for (int i=0; i < destination_stop_index_; i++) {
    //  check if at end of stop, next stop is same stop
    ++it;
  }
  return *it;
}

//  getter for index
int Route::GetIndex() const {
  return destination_stop_index_;
}

//  getter for name
std::string Route::GetName() const {
  return name_;
}

//  get list of stops
std::list<Stop*> Route::GetStops() {
  return stops_;
}

//  update route data
void Route::UpdateRouteData() {
  route_data_.id = GetName();
  route_data_.stops.clear();

  //  store stops in list and give to route_data_
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    Position *pos_ = new Position;
    StopData *stop_ = new StopData;

    // store pos values
    pos_ -> x = (*it) -> GetLong();
    pos_ -> y = (*it) -> GetLat();
    stop_ -> id = std::to_string((*it) -> GetId());
    stop_ -> position = *pos_;
    stop_ -> num_people = (*it) -> GetNumPassengers();
    route_data_.stops.push_back(*stop_);
  }
}

//  deallocate memory for Route
void Route::DeleteRoute() {
  //  deallocate data in lists
  delete[] &distances_between_;
  delete[] &stops_;
}

//  getter for route data
RouteData Route::GetRouteData() {
  return route_data_;
}

//  reports values for route
void Route::Report(std::ostream & out) {
  //  out << "Name: " << name_ << std::endl;
  out << "Num stops: " << num_stops_ << std::endl;
  out << "curr_stop: " << GetDestinationStop() -> GetId() << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it =
    stops_.begin(); it != stops_.end(); it++) {
    (*it)->Report(out);
    stop_counter++;
  }
}
