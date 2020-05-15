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
class StopTests : public ::testing::Test {
 protected:
  Stop* stop;
  virtual void SetUp() {
    stop = new Stop(0);
  }
  virtual void TearDown() {
    delete stop;
  }
};

/*******************************************************************************
* Test Cases
******************************************************************************/
//  Stop Tests
/* Need to test
* GetId() x
* AddPassengers(Passenger *) x
* Update() x
* Report(std::ostream &) x
* Passenger* UnloadPassenger() x
* bool CheckEmpty() x
* float GetLong() const x  inaccurate for unit tests excluded
* float GetLat() const x  inaccurate for unit tests excluded
* size_t GetNumPassengers() x
*/

//  check getters in stop
TEST_F(StopTests, StopConstructor) {
  EXPECT_EQ(stop->GetId(), 0)
  << "default id is off";
  /* floats are inaccurate for unit tests
  //  (tested not with unit tests)
  //  and received correct values for float
  EXPECT_EQ(stop->GetLong(), 44.973723);
  EXPECT_EQ(stop->GetLat(), -93.235365);
  */

  EXPECT_EQ(stop->GetNumPassengers(), 0)
  << "default num passengers is off";
  EXPECT_EQ(stop->CheckEmpty(), true)
  << "check empty is Off";
}

//  check loading unloading, report and update for stop
TEST_F(StopTests, StopPassengers) {
  //  initial report
  std::string expected_output_l1 =
  "ID: 0\n";
  std::string expected_output_l2 =
  "Passengers waiting: 0\n";
  std::string expected_output_1 =
  expected_output_l1 + expected_output_l2;
  testing::internal::CaptureStdout();
  stop -> Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "Default Report is Off";

  //  adding new passenger to stop
  Passenger* passenger_ = new Passenger();
  stop-> AddPassengers(passenger_);
  std::string expected_output_l3 =
  "ID: 0\nPassengers waiting: 1\n";
  std::string expected_output_l4 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 0\n";
  std::string expected_output_l5 =
  "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_output_2 =
  expected_output_l3 + expected_output_l4 + expected_output_l5;
  testing::internal::CaptureStdout();
  stop -> Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "Add Passenger Report is Off";

  //  updating time of passenger at stop
  stop -> Update();
  std::string expected_output_l8 =
  "ID: 0\nPassengers waiting: 1\n";
  std::string expected_output_l9 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 1\n";
  std::string expected_output_l10 =
  "\tWait at Stop: 1\n\tTime on bus: 0\n";
  std::string expected_output_4 =
  expected_output_l8 + expected_output_l9 + expected_output_l10;
  testing::internal::CaptureStdout();
  stop -> Report(std::cout);
  std::string output4 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output4, expected_output_4)
  << "Update Passenger Report is Off";

  //  unloading passenger at stop
  stop -> UnloadPassenger();
  std::string expected_output_l6 =
  "ID: 0\n";
  std::string expected_output_l7 =
  "Passengers waiting: 0\n";
  std::string expected_output_3 =
  expected_output_l6 + expected_output_l7;
  testing::internal::CaptureStdout();
  stop -> Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, expected_output_3)
  << "Unload Report is Off";
}
