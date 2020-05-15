/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>
#include <string>

#include "src/passenger_generator.h"
#include "src/stop.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerGenerator;
class Stop;
//  class RouteData;

/**
 * @brief Holds list of stops and distances between stops.
 * Bus travels on route going through the list of stops.
 */
class Route {
 public:
   /**
   * @brief Constructs a Route taking in a name, pointer
   * array of stops, array of distances, and number of stops
   *
   *
   * @param[in] string holding a name of a created Route
   * @param[in] Stop ** Array of Stop pointers for list of stops in route
   * @param[in] double * Array of distances to check distance between stops
   * @param[in] int holding number of stops in the route
   */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
  /**
  * @brief creates a clone of Route
  */
  Route * Clone();
  /**
  * @brief Update generates new passengers for stops and
  * calls updates for each stop in route
  */
  void Update();
  /**
  * @brief Reports variables of Route
  * @param[in] location of where to print
  */
  void Report(std::ostream&);
  /**
  * @brief check to see if index (bus) on the route is at last stop
  */
  bool IsAtEnd() const;
  /**
  * @brief changes destination_stop_ to next stop on route
  */
  void NextStop();  // Change destination_stop_ to next stop
  /**
  * @brief getter for destination_stop_
  */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  /**
  * @brief getter for total route distance
  */
  double GetTotalRouteDistance() const;
  /**
  * @brief getter for distance between current stop and next stop
  */
  double GetNextStopDistance() const;
  /**
  * @brief getter for count of stops
  */
  int GetNumStops() const;
  /**
  * @brief getter for index
  */
  int GetIndex() const;
  /**
  * @brief getter for nextstop
  */
  Stop * GetNextStop() const;
  /**
  * @brief getter for nextstop
  */
  Stop * GetPrevStop() const;
  /**
  * @brief getter for name
  */
  std::string GetName() const;
  /**
  * @brief getter list of stops
  */
  std::list<Stop*> GetStops();
  /**
  * @brief update route data
  */
  void UpdateRouteData();
  /**
  * @brief getter for route data
  */
  RouteData GetRouteData();
  /**
  * @brief deallocate data
  */
  void DeleteRoute();

 private:
   /**
   * @brief gnenerates passengers to stops in route
   */
  struct RouteData route_data_;
  int GenerateNewPassengers();       // generates passengers on its route
  //!  holds passenger generator
  PassengerGenerator * generator_;
  //!  holds list of stops that composes route
  std::list<Stop *> stops_;
  //!  holds list of distances that are between each stop
  std::list<double> distances_between_;  // length = num_stops_ - 1
  //!  holds name of route
  std::string name_;
  //!  holds number of stops in route
  int num_stops_;
  //!  holds the current index of where bus is on route
  int destination_stop_index_;  // init is needed
  //!  holds the stop destination
  Stop * destination_stop_;
  //!  total distance travelled on route
  double trip_time_;  //  derived data - total distance travelled on route
};
#endif  //  SRC_ROUTE_H_
