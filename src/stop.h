/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_STOP_H_
#define SRC_STOP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Bus;
/**
 * @brief locations where buses travel to and fro
 */
class Stop {
 public:
  /**
  * @brief Constructs a Stop taking in an int id and standard
  * double values that represent longitude and latitude of stop
  *
  *
  * @param[in] int holding id of created Stop
  * @param[in] double holding longitude of Stop
  * @param[in] double holding latitude of Stop
  */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Adding passengers to the stop (from the generator)
  /**
  * @brief Getter for Stop ID
  */
  int GetId() const;
  /**
  * @brief Adds a passenger to Stop
  *
  * @param[in] Passenger * holds passenger that will be stored at stop
  */
  int AddPassengers(Passenger *);
  /**
  * @brief Updates all time of passengers at that particular stop
  */
  void Update();
  /**
  * @brief Reports variables of stop
  *
  * @param[in] std::ostream & holds location to report to
  */
  void Report(std::ostream &) const;
  /**
  * @brief unloads a passenger from stop
  */
  Passenger* UnloadPassenger();
  /**
  * @brief check to see if passenger list is empty
  */
  bool CheckEmpty();
  /**
  * @brief get longitude
  */
  float GetLong() const;
  /**
  * @brief get latitude
  */
  float GetLat() const;
  /**
  * @brief get num of passengers at stop
  */
  size_t GetNumPassengers();

 private:
  //!  holds id of stop
  int id_;
  //!  holds list of passengers at stop
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  //!  holds longitude value of stop
  double longitude_;
  //!  holds latitutde value of stop
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
