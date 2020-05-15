/**
* @file configuration_simulator.cc
*
* @copyright 2019 3081 Staff, All rights reserved.
*/
#include "src/configuration_simulator.h"

//  initializes proto routes to hold routes from config txt
ConfigSimulator::ConfigSimulator(ConfigManager* config_, int bus_init_) {
  configM_ = config_;
  start_bus_ = bus_init_;
  prototype_routes_ = configM_->GetRoutes();
}

//  initializes sim
bool ConfigSimulator::Start() {
  simulation_time_elapsed_ = 0;
  int num_round_trips_ = 1;
  for (int i = 0; i < num_round_trips_; i++) {
    time_since_last_bus_generation_.push_back(0);
  }

  //  prototypeRoutes already hold all routes needed
  //  print a report of all routes
  std::cout << "testing" << std::endl;
  for (int i =0 ; i < static_cast<int> (prototype_routes_.size()); i++) {
    prototype_routes_[i] -> Report(std::cout);
  }
  bus_counters_.push_back(10000);
  //  when bus starts getting created
  bus_start_timings_.push_back(start_bus_);
  return true;
}

//  updates simulator for each time step
bool ConfigSimulator::Update() {
  //  increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  //  various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter =
  bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
  prototype_routes_.begin();

  //  increase each time since last bus
  //  various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
    it != time_since_last_bus_generation_.end();
    it++, bus_gen_timing_iter++, bus_counter_iter++) {
      (*it)++;
      //  if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      //  create a new bus! routes are:
      //  prototype_routes_[index * 2] & prototype_routes_[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;
      //   move set to 1
      //   max passengers set to 60
       active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
        outbound -> Clone(), inbound -> Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  //  for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
    bus_iter != active_buses_.end(); bus_iter++) {
    //  update bus
    (*bus_iter)->Update();
    //  bus report
    (*bus_iter)->Report(std::cout);

  //  REQUIRES USE OF IsTripComplete, which was not required
  //  Buses which are "done" will just keep having Update() called
  //   Students MAY need to deal with this, not sure yet...
  //  remove bus if trip is complete
    if ((*bus_iter)->IsTripComplete()) {
      (*bus_iter)-> DeallocateRoutes();
       bus_iter = active_buses_.erase(bus_iter);
       bus_iter--;
    }
  }
  //  for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
    route_iter != prototype_routes_.end(); route_iter++) {
    //  update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }
  return true;
}

//  deconstructor will do later
//  deallocation purposes
ConfigSimulator::~ConfigSimulator() {}
