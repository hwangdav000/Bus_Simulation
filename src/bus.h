/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
//  class BusData;
/**
* @brief Travels on route going through stops unloading and loading passengers
*/
class Bus {
 public:
  /**
  * @brief Constructs a Bus with a standard capacity and speed taking in a name and routes
  *
  *
  * @param[in] string holding a name of a created bus
  * @param[in] Route * holding the array of stops for outgoing routes
  * @param[in] Route * holding the array of stops for incoming routes
  * @param[in] int holding max capacity of created bus
  * @param[in] double holding the speed of the created bus
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  /**
  * @brief Loads a passenger onto the bus with method taking in passenger specified
  *
  * @param[in] Passenger * holding the pointer of the passenger bus should load
  */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
  * @brief Unloads passengers from bus if it is their destination
  *
  */
  bool UnloadPassengers();  //  unload passenger
  /**
  * @brief Moves bus affecting remaining distance to stop
  * according to speed
  *
  */
  bool Move();
  /**
  * @brief Checks whether bus is at stop or not and
  * either if it is on the outgoing route or the incoming route. Checks
  * if at stop on respective route and then updates Bus so if at stop
  * will load and unload passengers then move and update time of passengers
  * on bus or if not at stop will just move and update the time of passengers
  */
  void Update();
  /**
  * @brief reports the essential variables of Bus such as the name of the
  * bus, speed, distance to next stop, etc
  *
  * @param[in] location of where it prints to
  */
  void Report(std::ostream &);
  /**
  * @brief checks to see if bus has visited all the stops with both the outgoing
  * route and incoming route
  */
  bool IsTripComplete();
  /**
  * @brief unloads all passengers
  */
  void DestroyBus();
  /**
  * @brief Depending on incoming or outgoing route
  * unloads and loads passenger from a stop
  *
  * @param[in] Route * takes in incoming or outgoing route
  * depending on what route the bus is on
  */
  void Process(Route *);
  /**
  * @brief updates time of passengers on bus
  */
  void UpdatePass();
  /**
  * @brief populates busdata struct with latst information
  */
  void UpdateBusData();
  /**
  * @brief obtain busdata struct
  */
  BusData GetBusData();
  /**
  * @brief get name of bus
  */
  std::string GetName() const;
  /**
  * @brief get pointer of next stop for bus
  */
  Stop * GetNextStop();
  /**
  * @brief get num of passengers on bus
  */
  size_t GetNumPassengers();
  /**
  * @brief get max capacity of bus
  */
  int GetCapacity();
  /**
  * @brief deallocates data
  *
  */
  void DeallocateRoutes();

 private:
  //!  checks to see if bus is loading or not at a stop
  bool loading_;
  //!  holds bus data
  struct BusData bus_data_;
  //!  check to see if bus is at first stop outgoing route
  bool f_stop_;
  //!  check to see if bus is at first stop of incoming route
  bool s_stop_;
  //!  check to see when bus is loading or unloading passengers
  bool load_check_;
  //!  check to see if bus is done with incoming_route
  bool inbound_;
  //!  check to see if bus is done with outgoing_route
  bool outbound_;
  //!  list of passengers in bus
  std::list<Passenger *> passengers_;
  //!  holds limit of passengers that bus can carry
  int passenger_max_capacity_;
  //!  holds name of bus
  std::string name_;
  //!  holds distance that is traveled in one time step
  double speed_;  // could also be called "distance travelled in one time step"
  //!  holds a route * of outgoing route
  Route * outgoing_route_;
  //!  holds a route * of incoming route
  Route * incoming_route_;
  //!  holds distance_remaining indicating whether at stop or not
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
};
#endif  // SRC_BUS_H_
