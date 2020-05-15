/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string.h>
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief Passenger wait at stop or it loaded onto buses. Keeps track of time
  */
class Passenger {  // : public Reporter {
 public:
  /**
  * @brief Constructs a passenger with a standard name and id.
  *
  *
  * @param[in] int holding an id number
  * @param[in] string holding a name of a created passenger.
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
  * @brief updates the time of passenger by 1
  * passenger has two times: time on bus, wait at stop
  */
  void Update();
  /**
  * @brief function to know when passenger is on bus
  * then first time it is called sets time on bus to 1
  */
  void GetOnBus();
  /**
  * @brief gets the total wait of time on bus and wait at stop
  */
  int GetTotalWait() const;
  /**
  * @brief checks to see if passenger is on bus
  */
  bool IsOnBus() const;
  /**
  * @brief get destination that the passenger wants to go to
  */
  int GetDestination() const;
  /**
  * @brief Reports the variables of passenger like name, total wait,
  * time on bus, etc
  *
  * @param[in] location of where it prints to
  */
  void Report(std::ostream &) const;
  /**
  * @brief getter for name
  */
  std::string GetName() const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  //  global count, used to set ID for new instances
};
#endif  //  SRC_PASSENGER_H_
