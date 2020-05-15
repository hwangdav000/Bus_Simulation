/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_FACTORY_H_
#define SRC_PASSENGER_FACTORY_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/passenger.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of passengers.
 *
 * Calls to \ref Generate function to get a new instance of a passenger.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class PassengerFactory {
 public:
 /**
  * @brief Generation of a passenger with a randomized name and random destination within bounds.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] curr_stop Current stop, left bound (not-inclusive)
  * @param[in] last_stop Last stop, right bound (inclusive)
  *
  * @return Passenger object with name and destination.
  */
  static Passenger * Generate(int, int);
 private:
 /**
  * @brief Generation of randomized passenger name from prefix, stems and suffixes.
  *
  * @return Randomized passenger name.
  */
  static std::string NameGeneration();
};
#endif  //  SRC_PASSENGER_FACTORY_H_
