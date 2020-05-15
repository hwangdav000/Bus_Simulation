/**
* @file configuration_simulator.h
*
* @copyright 2019 3081 Staff, All rights reserved.
*/
#ifndef SRC_CONFIGURATION_SIMULATOR_H_
#define SRC_CONFIGURATION_SIMULATOR_H_

#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <list>

#include "src/config_manager.h"
#include "src/simulator.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/bus.h"

class ConfigSimulator : public Simulator {
 public:
   /**
   * @brief takes in configuration and bus initial time and creates sim
   *
   * @param[in] config_ holds config manager* to create routes
   * @param[in] bus_init_ holds bus init time
   */
  explicit ConfigSimulator(ConfigManager* config_, int bus_init_);
  ~ConfigSimulator();
  /**
  * @brief starts config sim where time = 0 and initalizes passenger
  *
  */
  bool Start() override;
  /**
  * @brief updates config sim
  *
  */
  bool Update() override;

 private:
    //!  holds all the routes given by config manager
    std::vector<Route*> prototype_routes_;
    //!  holds count of buses
    std::vector<int> bus_counters_;
    //!  holds bus initial start timings
    std::vector<int> bus_start_timings_;
    //!  holds last time since bus generated
    std::vector<int> time_since_last_bus_generation_;
    //!  holds time that has passed in simulation
    int simulation_time_elapsed_;
    //!  holds start time of first bus
    int start_bus_;
    //!  holds config manager which gives routes
    ConfigManager* configM_;
};

#endif  //  SRC_CONFIGURATION_SIMULATOR_H_
