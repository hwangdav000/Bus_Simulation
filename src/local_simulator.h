/**
 * @file local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_LOCAL_SIMULATOR_H_
#define SRC_LOCAL_SIMULATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "src/simulator.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief simulates a local sim
*/
class LocalSimulator : public Simulator {
 public:
  explicit LocalSimulator(std::string ptr);
  ~LocalSimulator();
  /**
  * @brief starts local sim where time = 0 and initalizes passenger
  *
  */
  bool Start() override;
  /**
  * @brief updates time in local sim
  */
  bool Update() override;

 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
  std::string of_ptr_s;
};

#endif  // SRC_LOCAL_SIMULATOR_H_
