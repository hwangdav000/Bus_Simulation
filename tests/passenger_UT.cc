/**
 * @file passenger_UT.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
/* STUDENTS: YOU MUST ADD YOUR PASSENGER UNIT TESTS TO THIS FILE. FORMAT YOUR
 * TESTS TO FIT THE SPECIFICATIONS GIVEN BY THE TESTS PROVIDED IN THIS FILE.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <gtest/gtest.h>
#include "../src/passenger.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
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

//  isOnBus tested by constructor
TEST_F(PassengerTests, Constructor) {
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
}

//  check GetDestination and print statements
TEST_F(PassengerTests, DestPrintTests) {
  //  test getdestination
  Passenger p1(10, "TestName");
  EXPECT_EQ(p1.GetDestination(), 10)
  << "get destination is incorrect";

  //  Test default report statements
  //  need to separate strings as >= 80 chars
  std::string expected_output_M1 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 0\n";
  std::string expected_output_M12 =
  "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_output_1 =
  expected_output_M1 + expected_output_M12;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "default report is off";

  //  test p1 report statements
  std::string expected_output_M2 =
  "Name: TestName\nDestination: 10\nTotal Wait: 0\n";
  std::string expected_output_M21 =
  "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_output_2 =
  expected_output_M2 + expected_output_M21;
  testing::internal::CaptureStdout();
  p1.Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "p1 report is off";
}
/*
//  test total wait, getonbus
TEST_F(PassengerTests, BusWaitTests) {
  //  Test default wait
  EXPECT_EQ(passenger-> GetTotalWait(), 0)
  << "default total time is incorrect";

  //  bus is expected to update then getonbus
  passenger-> Update();
  passenger -> GetOnBus();
  EXPECT_EQ(passenger-> GetTotalWait(), 1)
  << "GetOnBus is not working correctly";

  //  test to make sure calling function GetOnBus does not
  //  continually increment GetTotalWait
  passenger -> GetOnBus();
  passenger -> GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1)
  << "GetOnBus is continually incrementing time";
}
*/
//  test total wait, update
TEST_F(PassengerTests, UpdateWaitTests) {
  //  test update function
  EXPECT_EQ(passenger->GetTotalWait(), 0)
  << "default total time is incorrect";
  passenger -> Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1)
  << "update is not working correctly";
  passenger -> Update();
  passenger -> Update();
  EXPECT_EQ(passenger->GetTotalWait(), 3)
  << "update is not incrementing correctly";
}

//  test to check wait_at_stop_ and time_on_bus_
//  are updating correctly with report
/*
TEST_F(PassengerTests, TimeTests) {
  //  check that wait at stop is at 0 and time on bus is 0
  //  Test default report statements
  std::string expected_output_M1 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 0\n";
  std::string expected_output_M12 =
  "\tWait at Stop: 0\n\tTime on bus: 0\n";
  std::string expected_output_1 =
  expected_output_M1 + expected_output_M12;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "default report is off";

  //  check update function is correctly incrementing wait at stop
  passenger -> Update();

  //  test for 1 update call
  std::string expected_output_M2 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 1\n";
  std::string expected_output_M21 =
  "\tWait at Stop: 1\n\tTime on bus: 0\n";
  std::string expected_output_2 =
  expected_output_M2 + expected_output_M21;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "update is off on wait at stop";

  //  test for 2 update calls
  passenger -> Update();
  passenger -> Update();
  std::string expected_output_M3 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 3\n";
  std::string expected_output_M31 =
  "\tWait at Stop: 3\n\tTime on bus: 0\n";
  std::string expected_output_3 =
  expected_output_M3 + expected_output_M31;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, expected_output_3)
  << "wait at stop incorrect on multiple calls to update";

  //  call for getonbus now timeonbus is now incremented
  passenger -> Update();
  passenger -> GetOnBus();

  //  test that time_on_bus_ is set to 1
  std::string expected_output_M4 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 4\n";
  std::string expected_output_M41 =
  "\tWait at Stop: 3\n\tTime on bus: 1\n";
  std::string expected_output_4 =
  expected_output_M4 + expected_output_M41;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output4 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output4, expected_output_4)
  << "GetOnBus is not correctly initializing Time on bus";

  //  check that time_on_bus_ is updating
  //  one call to update
  passenger -> Update();
  std::string expected_output_M5 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 5\n";
  std::string expected_output_M51 =
  "\tWait at Stop: 3\n\tTime on bus: 2\n";
  std::string expected_output_5 =
  expected_output_M5 + expected_output_M51;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output5 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output5, expected_output_5)
  << "update is off for time on bus";

  //  multiple calls to update
  passenger -> Update();
  passenger -> Update();
  std::string expected_output_M6 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 7\n";
  std::string expected_output_M61 =
  "\tWait at Stop: 3\n\tTime on bus: 4\n";
  std::string expected_output_6 =
  expected_output_M6 + expected_output_M61;
  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  std::string output6 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output6, expected_output_6)
  << "time on bus is off for multiple calls to update";
}
*/
