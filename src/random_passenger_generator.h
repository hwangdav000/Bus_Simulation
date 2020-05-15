/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  //  forward declaration

/**
 * @brief Generates Passengers randomly at stops
 */
class RandomPassengerGenerator : public PassengerGenerator{
 public:
  /**
  * @brief Constructs RandomPassengerGenerator which takes in a double list and
  * stop list
  *
  * @param[in] std::list<double> holds generation probabilities for a passenger
  * at a stop
  * @param[in] std::list<Stop *> holds the stops for which we want to generate
  * passengers to
  */
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
  * @brief generates passengers based on prob and stops given
  */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  //  SRC_RANDOM_PASSENGER_GENERATOR_H_
