/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus.h"

//  Constructor for bus
Bus::Bus(std::string name, Route * out,
  Route * in, int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  f_stop_ = true;
  s_stop_ = true;
  inbound_ = true;
  outbound_ = true;
  loading_ = false;
  distance_remaining_ = 0.0;
}

//  load passengers to bus from a stop
bool Bus::LoadPassenger(Passenger * new_passenger_) {
  //  check if max capacity
  while (static_cast<int> (passenger_max_capacity_) >
    static_cast<int> (passengers_.size())) {
    passengers_.push_front(new_passenger_);
    return true;
  }
  return false;
}

//  unload passengers from bus
bool Bus::UnloadPassengers() {
  //  iterate through passengers comparing dest to stop_id
  //  if matches passenger is unloaded from bus
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
      if (outbound_) {
        std::cout << (*it) -> GetDestination() << std::endl;
        std::cout << outgoing_route_ ->
        GetDestinationStop() -> GetId() << std::endl;
        if ((*it) -> GetDestination() == (outgoing_route_ ->
        GetDestinationStop() -> GetId())) {
              //  unload passenger and deallocate space
              Passenger * temp_ = *it;
              it = passengers_.erase(it);
              delete temp_;
              it--;
              loading_ = true;
        }
      } else {
        //  outbound
        if ((*it) -> GetDestination() == (incoming_route_ ->
        GetDestinationStop() -> GetId())) {
              //  unload passenger and deallocate space
              Passenger * temp_ = *it;
              it = passengers_.erase(it);
              delete temp_;
              it--;
              loading_ = true;
        }
      }
  }
  return 1;
}

//  move bus according to speed
bool Bus::Move() {
  if (distance_remaining_ > 0) {
    distance_remaining_ = distance_remaining_ - speed_;

    return true;
  }
  return false;
}

//  see if bus has completed both routes
bool Bus::IsTripComplete() {
  if (inbound_ == false && outbound_ == false) {
    return true;
  }
  return false;
}

//  bool Refuel() {
//  //This may become more complex in the future
//  fuel_ = max_fuel_;
//  }

//  unload and load passengers
void Bus::Process(Route * set_route_) {
  Stop * curr_stop_ = set_route_ -> GetDestinationStop();
  UnloadPassengers();
  //  load in all passengers from curr stop that are available
  while (!curr_stop_ -> CheckEmpty() &&
  static_cast<int> (passenger_max_capacity_) >
  static_cast<int> (passengers_.size())) {
    Passenger* new_pass_ = curr_stop_ -> UnloadPassenger();
    LoadPassenger(new_pass_);
    loading_ = true;
  }
}

//  update time of passengers on bus
void Bus::UpdatePass() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    if (!((*it) -> IsOnBus())) {
      (*it) -> GetOnBus();
    } else {
      (*it) -> Update();
    }
  }
}

//  deallocate all passengers and remove from bus all passengers
void Bus::DestroyBus() {
  for ( std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    Passenger * temp_ = *it;
    it = passengers_.erase(it);
    delete temp_;
  }
  passengers_.clear();
}

//  deallocate data for routes
//  might add more here later
void Bus::DeallocateRoutes() {
  delete incoming_route_;
  delete outgoing_route_;
}

//  two cases: inbound or outbound routes
//  unloads and loads if at stop and updates passengers
//  checks if tripcomplete and need to destory bus
void Bus::Update() {
  UpdateBusData();
  Move();
  loading_ = false;
  //  check to see if at last stop with remaining distance 0
  if (outbound_) {
    if (distance_remaining_  <= 0.0001) {
      if (outgoing_route_ -> IsAtEnd()) {
        outbound_ = false;
      }
      //  edge case: check if at very f_stop_ stop
      //  if so do not go to next stop to follow expected output
      if (f_stop_) {
        f_stop_ = false;
        distance_remaining_ = outgoing_route_ -> GetNextStopDistance();
      } else {
        outgoing_route_ -> NextStop();
        distance_remaining_ = outgoing_route_ -> GetNextStopDistance();
      }
      Process(outgoing_route_);
    }
  } else {
    if (inbound_) {
      if (distance_remaining_  <= 0.0001) {
        if (incoming_route_ -> IsAtEnd()) {
          inbound_ = false;
        }
        if (s_stop_) {
          s_stop_ = false;
          distance_remaining_ = incoming_route_ -> GetNextStopDistance();
        } else {
        incoming_route_ -> NextStop();
        distance_remaining_ = incoming_route_ -> GetNextStopDistance();
        }
        Process(incoming_route_);
      }
    }
  }
  if (IsTripComplete()) {
    DestroyBus();
  }
  //  update times of all passengers in buss
  UpdatePass();
}

//  Store data into BusData
//  need to have it seen at stop when loading or unloading passengers
void Bus::UpdateBusData() {
  Stop * CurrStop_;
  Stop * PrevStop_;
  if (outbound_) {
    CurrStop_ = outgoing_route_ -> GetDestinationStop();
    PrevStop_ = outgoing_route_ -> GetPrevStop();
  } else {
    CurrStop_ = incoming_route_ -> GetDestinationStop();
    PrevStop_ = incoming_route_ -> GetPrevStop();
  }

  //  if loading_ is true then at stop and unload/loading passengers
  //  else default
  float long_avg_;
  float lat_avg_;
  if (loading_) {
    long_avg_ = CurrStop_ -> GetLong();
    lat_avg_ = CurrStop_ -> GetLat();
  } else {
    long_avg_ = (CurrStop_ ->  GetLong() + PrevStop_ -> GetLong())/2.0;
    lat_avg_ = (CurrStop_ ->  GetLat() + PrevStop_ -> GetLat())/2.0;
  }struct Position pos_;
  pos_.x = long_avg_;
  pos_.y = lat_avg_;
  bus_data_.id = GetName();
  bus_data_.position = pos_;
  bus_data_.num_passengers = GetNumPassengers();
  bus_data_.capacity = GetCapacity();
}

//  get bus data
BusData Bus::GetBusData() {
  return bus_data_;
}
//  get name of bus
std::string Bus::GetName() const {
  return name_;
}

//  get next stop of bus
Stop * Bus::GetNextStop() {
  if (outbound_) {
    return (outgoing_route_ -> GetNextStop());
  } else {
    return (incoming_route_ -> GetNextStop());
  }
  return NULL;
}

//  get number of passengers in bus
size_t Bus::GetNumPassengers() {
  return passengers_.size();
}

//  get max capacity of Bus
int Bus::GetCapacity() {
  return passenger_max_capacity_;
}

//  report variables for bus
void Bus::Report(std::ostream & out) {
  //  get latitude and longitude of current bus stop (testing purposes)
  //  used for debugging
  /*
  Stop * CurrStop_;

  if (outbound_) {
    CurrStop_ = outgoing_route_ -> GetDestinationStop();
      out << "curr_stop : " << CurrStop_-> GetId() <<std::endl;
  } else {
    CurrStop_ = incoming_route_ -> GetDestinationStop();
      out << "curr_stop : " << CurrStop_-> GetId() <<std::endl;
  }
  */
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  //  cleans distance to 0
  if (distance_remaining_ <= 0.0001) {
    distance_remaining_ = 0;
  }
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it =
    passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
