/**
 * @file passenger.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */


#include "./passenger.h"
#include <iostream>
#include <string>

int Passenger::count_ = 0;

// Passenger constructor
Passenger::Passenger(int destination_stop_id, std::string name):
name_(name),
destination_stop_id_(destination_stop_id),
wait_at_stop_(0), time_on_bus_(0), id_(count_) {
  count_++;
}

//  getter for name
std::string Passenger::GetName() const {
  return name_;
}

//  updates time for passenger
void Passenger::Update() {
  if (!IsOnBus()) {
  wait_at_stop_++;
  } else {
    time_on_bus_++;
  }
}

//  checks if on bus and increments accordingly
void Passenger::GetOnBus() {
  //  since stop update is called first before we need to decrement
  //  wait at stop and increment now time on bus

  if (time_on_bus_ == 0) {
    wait_at_stop_--;
    time_on_bus_ = 1;
  }
}

//  get total wait
int Passenger::GetTotalWait() const {
  return wait_at_stop_+time_on_bus_;
}

//  see if passenger is on bus
bool Passenger::IsOnBus() const {
  if (time_on_bus_ > 0) {
    return true;
  }
  return false;
}

//  getter for destination
int Passenger::GetDestination() const {
  return destination_stop_id_;
}

//  reports values for passenger
void Passenger::Report(std::ostream & out) const {
  out << "Name: " << name_ << std::endl;
  out << "Destination: " << destination_stop_id_ << std::endl;
  out << "Total Wait: " << GetTotalWait() << std::endl;
  out << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  out << "\tTime on bus: " << time_on_bus_ << std::endl;
}
