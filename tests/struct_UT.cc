/**
 * @file struct_UT.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
 /*******************************************************************************
  * Includes
  ******************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <random>
#include <ctime>
#include "../src/bus.h"
#include "../src/route.h"
#include "../src/passenger.h"
#include "../src/random_passenger_generator.h"
#include "../src/data_structs.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StructTests : public ::testing::Test {
 protected:
  Passenger* passenger;
  virtual void SetUp() {
    passenger = new Passenger();
  }
  virtual void TearDown() {
    delete passenger;
  }
};
/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/* TEST for bus
void UpdateBusData();
BusData GetBusData();
std::string GetName() const;
Stop * GetNextStop();
size_t GetNumPassengers();
*/

//  test struct functions (BUS)
TEST_F(StructTests, BusConstructor) {
  //  tested by constructor
  Stop ** CC_EB_stops = new Stop *[3];
  Stop ** CC_WB_stops = new Stop *[3];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(1, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117);  //  Oak St & Washington Ave

  //  Westbound stops
  Stop stop_CC_WB_1(6, 47, -96);  //  st paul 2
  Stop stop_CC_WB_2(7, 46, -95);  //  st paul 1
  Stop stop_CC_WB_3(8, 45, -94);  //  before transit
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  double * CC_EB_distances = new double[2];
  double * CC_WB_distances = new double[2];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;
  CC_WB_distances[0] = 6;
  CC_WB_distances[1] = 10;
  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  CC_EB_probs.push_back(.025);  //  O&W
  std::list<double> CC_WB_probs;  //  realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35);  //  stp 2
  CC_WB_probs.push_back(.05);  //  stp 1
  CC_WB_probs.push_back(.01);  //  post-transit
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 3, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  CC_WB_distances, 3, &CC_WB_generator);
  Bus bus_("0000", &CC_EB, &CC_WB, 60, 10);

  //  test name
  EXPECT_EQ(bus_.GetName(), "0000")
  << "name of bus is correct";

  //  tset capacity
  EXPECT_EQ(bus_.GetCapacity(), 60)
  << "bus capacity is correct";

  //  test numb of passengers (init = 0)
  EXPECT_EQ(bus_.GetNumPassengers(), 0)
  << "init passengers is correct";

  //  going outbound so second stop on that route
  EXPECT_EQ(bus_.GetNextStop(), CC_EB.GetNextStop())
  << "next stop is correct";

  // test constructor
  struct Position pos_;
  pos_.x = 6.0;
  pos_.y = 4.0;
  //  update bus data
  struct BusData temp;
  temp.id = "0000";
  temp.position = pos_;
  temp.num_passengers = 0;
  temp.capacity = 60;
  bus_.UpdateBusData();

  //  check getbusdata
  EXPECT_EQ((bus_.GetBusData()).id, temp.id)
  << "busdata struct id not correct";
  EXPECT_EQ((bus_.GetBusData()).num_passengers, 0)
  << "busdata struct num passengers not correct";
  EXPECT_EQ((bus_.GetBusData()).capacity, 60)
  << "busdata struct capacity not correct";
  EXPECT_EQ((bus_.GetBusData()).position.x, 1)
  << "busdata struct pos x not correct";
  EXPECT_EQ((bus_.GetBusData()).position.y, 1)
  << "busdata struct pos y not correct";

  //  test multiple updates get to next stop
  bus_.Update();
  bus_.Update();
  bus_.UpdateBusData();

  //  check getbusdata
  EXPECT_EQ((bus_.GetBusData()).id, temp.id)
  << "busdata struct id not correct";
  EXPECT_EQ((bus_.GetBusData()).num_passengers, 0)
  << "busdata struct num passengers not correct";
  EXPECT_EQ((bus_.GetBusData()).capacity, 60)
  << "busdata struct capacity not correct";
  EXPECT_EQ((bus_.GetBusData()).position.x, 5.5)
  << "busdata struct pos x not correct";
  EXPECT_EQ((bus_.GetBusData()).position.y, 3.5)
  << "busdata struct pos y not correct";
}

//  test struct funcitons (ROUTE)
TEST_F(StructTests, RouteConstructor) {
  //  tested by constructor
  Stop ** CC_EB_stops = new Stop *[3];
  Stop ** CC_WB_stops = new Stop *[3];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(0, 0.0, 0.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 10.0);  //  student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117);  //  Oak St & Washington Ave
  //  Westbound stops
  Stop stop_CC_WB_1(6, 47, -96);  //  st paul 2
  Stop stop_CC_WB_2(7, 46, -95);  //  st paul 1
  Stop stop_CC_WB_3(8, 45, -94);  //  before transit
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  double * CC_EB_distances = new double[2];
  double * CC_WB_distances = new double[2];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;
  CC_WB_distances[0] = 6;
  CC_WB_distances[1] = 10;
  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  CC_EB_probs.push_back(.025);  //  O&W
  std::list<double> CC_WB_probs;  //  realistic .35, .05, .01
  CC_WB_probs.push_back(.35);  //  stp 2
  CC_WB_probs.push_back(.05);  //  stp 1
  CC_WB_probs.push_back(.01);  //  post-transit
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs,
  CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs,
  CC_WB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 3, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  CC_WB_distances, 3, &CC_WB_generator);
  EXPECT_EQ(CC_EB.GetName(), "Campus Connector - Eastbound")
  << "route name incorrect";
  EXPECT_EQ(CC_EB.GetNextStop(), &stop_CC_EB_2)
  << "route next stop incorrect";

  //  need to test list of stops
  std::list<Stop *> stop_temp_;
  stop_temp_ = CC_EB.GetStops();
  std::list<Stop *>::const_iterator it = stop_temp_.begin();
  for (int i=0; i < 3; i++) {
    EXPECT_EQ((*it) -> GetId(), CC_EB_stops[i] ->GetId())
    << "stop list incorrect";
    ++it;
  }
  //////////////////////////////////////////////
  //  update bus data
  std::vector<StopData> test_stop;

  //  store stop data list
  //  need id pos numpeople
  for (int i = 0 ; i< 3; i++) {
    Position pos_;
    StopData stop_;

    // store pos values
    pos_.x = CC_EB_stops[i] -> GetLong();
    pos_.y = CC_EB_stops[i] -> GetLat();

    // store stopdata values

    stop_.id = std::to_string(CC_EB_stops[i] -> GetId());
    stop_.position = pos_;
    stop_.num_people = CC_EB_stops[i] -> GetNumPassengers();
    test_stop.push_back(stop_);
  }
  struct RouteData route_temp;
  route_temp.id = "Campus Connector - Eastbound";
  route_temp.stops = test_stop;

  //  test update and get route data
  CC_EB.UpdateRouteData();
  EXPECT_EQ((CC_EB.GetRouteData()).id, route_temp.id)
  << "route data struct name not correct";
  std::vector<StopData>::iterator it2 = route_temp.stops.begin();
  std::vector<StopData> vector_stops_ = CC_EB.GetRouteData().stops;
  for (auto it = vector_stops_.begin();
  it != vector_stops_.end(); it++) {
      EXPECT_EQ((*it).id, (*it2).id)
      << "route data struct id not correct";
      EXPECT_EQ((*it).num_people, (*it2).num_people)
      << "route data struct numPeople not correct";
      EXPECT_EQ((*it).position.x, (*it2).position.x)
      << "route data struct pos x not correct";
      EXPECT_EQ((*it).position.y, (*it2).position.y)
      << "route data struct pos y not correct";
      it2++;
  }
}
