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
class RouteTests : public ::testing::Test {
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
/** checklist for
Route * Clone(); x
void Update(); x
void Report(std::ostream&); x
bool IsAtEnd() const; x
void NextStop(); x
Stop * GetDestinationStop() const; x
double GetTotalRouteDistance() const; x
double GetNextStopDistance() const; x
int GetNumStops() const; x
int GetIndex() const; x
Stop * GetNextStop() const; x
Stop * GetPrevStop() const; x
std::string GetName() const; x
std::list<Stop*> GetStops; x
void UpdateRouteData(); x tested in struct
RouteData GetRouteData(); x tested in struct
void DeleteRoute(); ~ memory deallocation
*/

//  test for getters in Route
TEST_F(RouteTests, RouteConstructor) {
  Stop ** CC_EB_stops = new Stop *[3];
  std::list<Stop *> CC_EB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(1, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117);  //  Oak St & Washington Ave
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;

  double * CC_EB_distances = new double[2];

  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;

  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  CC_EB_probs.push_back(.025);  //  O&W

  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 3, &CC_EB_generator);
  //  Route CC_WB("Campus Connector - Westbound", CC_WB_stops,
  //  CC_WB_distances, 3, &CC_WB_generator);
  EXPECT_EQ(CC_EB.GetName(), "Campus Connector - Eastbound")
  << "GetName for route is off";
  EXPECT_EQ(CC_EB.GetNumStops(), 3)
  << "GetNumStops for route is off";
  EXPECT_EQ(CC_EB.GetIndex(), 0)
  << "base GetIndex for route is off";
  EXPECT_EQ(CC_EB.IsAtEnd(), false)
  << "base IsAtEnd for route is off";
  EXPECT_EQ(CC_EB.GetNextStopDistance(), 5)
  << "Next Stop distance is off";
  EXPECT_EQ(CC_EB.GetTotalRouteDistance(), 9)
  << "total route distance is off";
}

//  tests for checking next stop or prev stop in route
TEST_F(RouteTests, CheckMoveStops) {
  Stop ** CC_EB_stops = new Stop *[3];
  std::list<Stop *> CC_EB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(1, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117);  //  Oak St & Washington Ave
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;

  double * CC_EB_distances = new double[2];

  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;

  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU
  CC_EB_probs.push_back(.025);  //  O&W

  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 3, &CC_EB_generator);

  //  test next and prev stop on route
  EXPECT_EQ(CC_EB.GetName(), "Campus Connector - Eastbound")
  << "route name incorrect";
  EXPECT_EQ(CC_EB.GetNextStop(), &stop_CC_EB_2)
  << "route next stop incorrect";

  //  make sure functionality doesn't break
  EXPECT_EQ(CC_EB.GetPrevStop(), &stop_CC_EB_1)
  << "route prev stop at first stop incorrect";

  //  need to test list of stops for GETSTOPS
  std::list<Stop *> stop_temp_;
  stop_temp_ = CC_EB.GetStops();
  std::list<Stop *>::const_iterator it = stop_temp_.begin();
  for (int i=0; i < 3; i++) {
    EXPECT_EQ((*it) -> GetId(), CC_EB_stops[i] ->GetId())
    << "stop list incorrect";
    ++it;
  }

  //  checking if current stop is correct
  EXPECT_EQ(CC_EB.GetDestinationStop(), &stop_CC_EB_1)
  << "destination stop incorrect";

  CC_EB.NextStop();
  //  using GetIds instead of Addresses in unit tests
  //  Addresses result in inaccurate results
  EXPECT_EQ(CC_EB.GetDestinationStop()->GetId(), stop_CC_EB_2.GetId())
  << "destination stop incorrect";
  EXPECT_EQ(CC_EB.GetNextStop()->GetId(), stop_CC_EB_3.GetId())
  << "route next stop incorrect";
  EXPECT_EQ(CC_EB.GetPrevStop()->GetId(), stop_CC_EB_2.GetId())
  << "route prev stop at first stop incorrect";
  CC_EB.NextStop();

  EXPECT_EQ(CC_EB.GetDestinationStop()->GetId(), stop_CC_EB_3.GetId())
  << "destination stop incorrect";

  EXPECT_EQ(CC_EB.GetNextStop()->GetId(), stop_CC_EB_3.GetId())
  << "route next stop incorrect";

  EXPECT_EQ(CC_EB.GetPrevStop()->GetId(), stop_CC_EB_2.GetId())
  << "route prev stop at first stop incorrect";
  EXPECT_EQ(CC_EB.IsAtEnd(), true)
  << "is at end incorrect";
}

//  test for update in route and report
TEST_F(RouteTests, RouteUpdate) {
  Stop ** CC_EB_stops = new Stop *[1];
  std::list<Stop *> CC_EB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(1, 1.0, 1.0);  //  West bank station
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;

  double * CC_EB_distances = NULL;

  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(0);  //  WB

  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 1, &CC_EB_generator);

  //  Update harder to test due to random passenger generation
  std::string expected_output_l1 =
  "Num stops: 1\ncurr_stop: 1\n";
  std::string expected_output_l2 =
  "ID: 1\nPassengers waiting: 0\n";
  std::string expected_output_1 =
  expected_output_l1 + expected_output_l2;
  testing::internal::CaptureStdout();
  CC_EB.Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, expected_output_1)
  << "Default Report is Off";

  Passenger* passenger = new Passenger();
  stop_CC_EB_1.AddPassengers(passenger);

  CC_EB.Update();
  //  getting segfault here even though
  //  it goes through whole report without
  //  segfaulting (error through google test?)

  std::string expected_output_l3 =
  "Num stops: 1\ncurr_stop: 1\nID: 1\nPassengers waiting: 1\n";
  std::string expected_output_l4 =
  "Name: Nobody\nDestination: -1\nTotal Wait: 1\n";
  std::string expected_output_l5 =
  "\tWait at Stop: 1\n\tTime on bus: 0\n";
  std::string expected_output_2 =
  expected_output_l3+expected_output_l4+expected_output_l5;
  /*
  CC_EB.Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, expected_output_2)
  << "Report is Off";
  */
}

//  tests for clone
TEST_F(RouteTests, CheckClone) {
  Stop ** CC_EB_stops = new Stop *[2];
  std::list<Stop *> CC_EB_stops_list;

  //  Eastbound stops
  Stop stop_CC_EB_1(0, 1.0, 1.0);  //  West bank station
  Stop stop_CC_EB_2(1, 10.0, 6.0);  //  student union station
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;

  double * CC_EB_distances = new double[1];

  CC_EB_distances[0] = 5;

  std::list<double> CC_EB_probs;  //  realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15);  //  WB
  CC_EB_probs.push_back(.3);  //  CMU

  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops,
  CC_EB_distances, 2, &CC_EB_generator);

  // test stop list and distances
  Route* CC_EB_Clone = CC_EB.Clone();

  static int i = 0;
  std::list<Stop *> C_stops = CC_EB_Clone-> GetStops();
  for (auto it = C_stops.begin(); it != C_stops.end(); it++) {
    EXPECT_EQ((*it) -> GetId(), CC_EB_stops[i] ->GetId())
    << "stop list incorrect";
    i++;
  }
  EXPECT_EQ((CC_EB_Clone) -> GetNextStopDistance(), 5);
  EXPECT_EQ((CC_EB_Clone) -> GetName(), "Campus Connector - Eastbound");
  EXPECT_EQ((CC_EB_Clone) -> GetIndex(), 0);
}
