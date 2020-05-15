/**
 * @file stop.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <iostream>
#include <vector>

#include "./stop.h"

//  constructor for stop
Stop::Stop(int id, double longitude, double latitude) {
  //  Defaults to Westbound Coffman Union stop
  //  no initialization of list of passengers necessary
  id_ = id;
  longitude_ = longitude;
  latitude_ = latitude;
}

//  calls update to all Passengers in list
void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

//  add passengers to stop
int Stop::AddPassengers(Passenger * pass) {
  //  add the passenger to the stop
  passengers_.push_back(pass);
  return 0;
}

//  getter for stop id
int Stop::GetId() const {
  return id_;
}

//  unloads passenger to bus
Passenger* Stop::UnloadPassenger() {
  Passenger *pass_ = reinterpret_cast<Passenger *> (malloc(sizeof(Passenger)));
  pass_ = (passengers_.front());
  passengers_.pop_front();
  return pass_;
}

//  checks if stop is empty or not
bool Stop::CheckEmpty() {
  if (passengers_.empty()) {
    return true;
  }
  return false;
}

//  get stop longitude
float Stop::GetLong() const {
  return static_cast<float> (longitude_);
}

//  get stop latitude
float Stop::GetLat() const {
  return static_cast<float> (latitude_);
}
size_t Stop::GetNumPassengers() {
  return passengers_.size();
}

//  reports values to stop
void Stop::Report(std::ostream & out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " <<
  passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it =
    passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
