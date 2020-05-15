/**
* @file config_simulator.h
*
* @copyright 2019 3081 Staff, All rights reserved.
*/
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <algorithm>

#include "src/route.h"
#include "src/stop.h"
#include "src/random_passenger_generator.h"

class Route;
/**
* @brief takes in config txt and turns it into routes
*/
class ConfigManager {
 public:
    ConfigManager();
    ~ConfigManager();
    /**
    * @brief reads file and turns it into routes
    *
    */
    void ReadConfig(const std::string filename);
    /**
    * @brief getter for routes
    *
    */
    std::vector<Route *> GetRoutes() const { return routes_; }

 private:
    /**
    * @brief holds routes gotten from config text
    *
    */
    std::vector<Route *> routes_;
};

#endif  //  SRC_CONFIG_MANAGER_H_
