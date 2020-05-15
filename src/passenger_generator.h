/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  // forward declaration

/**
 * @brief Passenger Generator Class
 * Generation of a passenger which holds list of probabilities and stops
 */
class PassengerGenerator {
 public:
  /**
  * @brief Constructs PassengerGenerator which takes in a double list and
  * stop list
  *
  * @param[in] std::list<double> holds generation probabilities for a passenger
  * at a stop
  * @param[in] std::list<Stop *> holds the stops for which we want to generate
  * passengers to
  */
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  // Makes the class abstract, cannot instantiate and forces subclass override
  /**
  * @brief generates passengers based on prob and stops given
  */
  virtual int GeneratePassengers() = 0;  // pure virtual
 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;

  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
