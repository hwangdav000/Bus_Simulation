/**
* @file bus_UT.cc
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
//  struct functions for bus are tested in struct_UT
class BusTests : public ::testing::Test {
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
//  test checklist
/*
bool LoadPassenger(Passenger *); x  // returning revenue delta
bool UnloadPassengers();  // x  unload passenger
bool Move(); x
void Update(); x
void Report(std::ostream &); x
bool IsTripComplete(); x
void Destroy_Bus(); ~memory deallocation
void Process(Route *); x
void UpdatePass(); x
void UpdateBusData(); x struct_test
BusData GetBusData(); x struct_test
std::string GetName() const; x
Stop * GetNextStop(); x
size_t GetNumPassengers(); x
int GetCapacity(); x
void DeallocateRoutes(); ~memory deallocation
*/

//  test getter functions
TEST_F(BusTests, BusConstructor) {
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
  Bus bus_("0000", &CC_EB, &CC_WB, 60, 1);

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

  EXPECT_EQ(bus_.IsTripComplete(), false)
  << "is trip complete initial value correct";
}

//  tests for update
TEST_F(BusTests, BusUpdateReport) {
  Stop ** CC_EB_stops = new Stop *[2];
  Stop ** CC_WB_stops = new Stop *[2];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(0, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station

  //  Westbound stops
  Stop stop_CC_WB_1(2, 47, -96);  //  st paul 2
  Stop stop_CC_WB_2(3, 46, -95);  //  st paul 1
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  double * CC_EB_distances = new double[1];
  double * CC_WB_distances = new double[1];
  CC_EB_distances[0] = 5;
  CC_WB_distances[0] = 6;
  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  std::list<double> CC_WB_probs;  //  realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35);  //  stp 2
  CC_WB_probs.push_back(.05);  //  stp 1
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 2, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  CC_WB_distances, 2, &CC_WB_generator);
  Bus bus_("0000", &CC_EB, &CC_WB, 60, 4);

  //  test report
  //  distance to next stop is 0 as has not called update yet
  std::string expected_output_l1 =
  "Name: 0000\nSpeed: 4\nDistance to next stop: 0\n";
  std::string expected_output_l2 =
  "\tPassengers (0): \n";
  std::string expected_output_1 =
  expected_output_l1 + expected_output_l2;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "default report is off";

  //  tests for antother update distance should be initialized
  bus_.Update();
  std::string expected_output_l3 =
  "Name: 0000\nSpeed: 4\nDistance to next stop: 5\n";
  std::string expected_output_l4 =
  "\tPassengers (0): \n";
  std::string expected_output_2 =
  expected_output_l3 + expected_output_l4;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "default update is off";

  //  test for another update move should decrease distance by 1
  bus_.Update();
  std::string expected_output_l5 =
  "Name: 0000\nSpeed: 4\nDistance to next stop: 1\n";
  std::string expected_output_l6 =
  "\tPassengers (0): \n";
  std::string expected_output_3 =
  expected_output_l5 + expected_output_l6;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, expected_output_3)
  << "update is off";
}

//  test for loading unloading and reports
TEST_F(BusTests, BusLoading) {
  Stop ** CC_EB_stops = new Stop *[2];
  Stop ** CC_WB_stops = new Stop *[2];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(0, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station

  //  Westbound stops
  Stop stop_CC_WB_1(2, 47, -96);  //  st paul 2
  Stop stop_CC_WB_2(3, 46, -95);  //  st paul 1
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  double * CC_EB_distances = new double[1];
  double * CC_WB_distances = new double[1];
  CC_EB_distances[0] = 5;
  CC_WB_distances[0] = 6;
  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  std::list<double> CC_WB_probs;  //  realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35);  //  stp 2
  CC_WB_probs.push_back(.05);  //  stp 1
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 2, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  CC_WB_distances, 2, &CC_WB_generator);
  Bus bus_("0000", &CC_EB, &CC_WB, 60, 1);

  //  Process uses unload and load passengers
  Passenger* passenger = new Passenger(0);
  bus_.LoadPassenger(passenger);

  std::string expected_output_l7 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 0\n";
  std::string expected_output_l8 =
  "\tPassengers (1): \n";
  std::string expected_output_M1 =
  "Name: Nobody\nDestination: 0\nTotal Wait: 0\n";
  std::string expected_output_M2 =
  "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_output_l9 =
  expected_output_M1 + expected_output_M2;
  std::string expected_output_4 =
  expected_output_l7 + expected_output_l8 + expected_output_l9;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output4 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output4, expected_output_4)
  << "load passenger is off";

  //  update pass subtracts wait at stop by 1
  //  when enters on 1 and turn on_bus to true
  //  and updates time on bus by 1

  bus_.UpdatePass();

  std::string expected_output_ll7 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 0\n";
  std::string expected_output_ll8 =
  "\tPassengers (1): \n";
  std::string expected_output_M3 =
  "Name: Nobody\nDestination: 0\nTotal Wait: 0\n";
  std::string expected_output_M4 =
  "\tWait at Stop: -1\n\tTime on bus: 1\n";
  std::string expected_output_ll9 =
  expected_output_M3 + expected_output_M4;
  std::string expected_output_7 =
  expected_output_ll7 + expected_output_ll8 + expected_output_ll9;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output7 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output7, expected_output_7)
  << "update passenger is off";

  //  test for unloading
  bus_.UnloadPassengers();

  std::string expected_output_l10 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 0\n";
  std::string expected_output_l11 =
  "\tPassengers (0): \n";
  std::string expected_output_5 =
  expected_output_l10 + expected_output_l11;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output5 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output5, expected_output_5)
  << "unload failed";

  //  test for processing which is unloading of passenger and takes
  //  in passengers at current stop (0)
  bus_.Process(&CC_EB);

  std::string expected_output_l12 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 0\n";
  std::string expected_output_l13 =
  "\tPassengers (0): \n";
  std::string expected_output_6 =
  expected_output_l12 + expected_output_l13;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output6 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output6, expected_output_6)
  << "process failed";
}

//  test functions inside of update
TEST_F(BusTests, BusUpdate) {
  Stop ** CC_EB_stops = new Stop *[2];
  Stop ** CC_WB_stops = new Stop *[2];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(0, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station

  //  Westbound stops
  Stop stop_CC_WB_1(2, 47, -96);  //  st paul 2
  Stop stop_CC_WB_2(3, 46, -95);  //  st paul 1
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  double * CC_EB_distances = new double[1];
  double * CC_WB_distances = new double[1];
  CC_EB_distances[0] = 5;
  CC_WB_distances[0] = 6;
  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  std::list<double> CC_WB_probs;  //  realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35);  //  stp 2
  CC_WB_probs.push_back(.05);  //  stp 1
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 2, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  CC_WB_distances, 2, &CC_WB_generator);
  Bus bus_("0000", &CC_EB, &CC_WB, 60, 1);

  //  tests for update and move which decreases remaining distance
  bus_.Update();
  bus_.Move();
  std::string expected_output_l1 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 4\n";
  std::string expected_output_l2 =
  "\tPassengers (0): \n";
  std::string expected_output_1 =
  expected_output_l1 + expected_output_l2;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "move is off";

  //  multiple calls to move
  bus_.Move();
  bus_.Move();

  std::string expected_output_l3 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 2\n";
  std::string expected_output_l4 =
  "\tPassengers (0): \n";
  std::string expected_output_2 =
  expected_output_l3 + expected_output_l4;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "multiple moves is off";

  //  move after distance to next stop is 0
  bus_.Move();
  bus_.Move();
  bus_.Move();

  std::string expected_output_l5 =
  "Name: 0000\nSpeed: 1\nDistance to next stop: 0\n";
  std::string expected_output_l6 =
  "\tPassengers (0): \n";
  std::string expected_output_3 =
  expected_output_l5 + expected_output_l6;
  testing::internal::CaptureStdout();
  bus_.Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, expected_output_3)
  << "move after 0 is off";
}
