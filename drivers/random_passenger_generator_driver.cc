#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>

#include "passenger.h"
#include "stop.h"
#include "random_passenger_generator.h"

int main() {
  
  int rounds = 10; //Number of rounds of generation to simulate in test
  
  srand((long)time(NULL)); //Seed the random number generator...
  
  
  Stop stop1(1); //student union station
  Stop stop2(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop3(3, 45, -94); //?
  Stop stop4(4, 46, -95); //?
  Stop stop5(5, 47, -96);
  
  std::list<Stop *> my_stops;
  my_stops.push_back(&stop1);
  my_stops.push_back(&stop2);
  my_stops.push_back(&stop3);
  my_stops.push_back(&stop4);
  my_stops.push_back(&stop5);
  
  std::list<double> probs;
  probs.push_back(.1);
  probs.push_back(.5);
  probs.push_back(.2);
  probs.push_back(.05);
  probs.push_back(0); 
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  RandomPassengerGenerator generator(probs, my_stops);
  int total_generated = 0;
  
  std::cout << "/*\n *\n * Initial Report\n *\n*/" << std::endl;
  
  for (std::list<Stop *>::iterator stop_iter = my_stops.begin(); stop_iter != my_stops.end(); stop_iter++) {
    (*stop_iter)->Update();
    std::cout  << std::endl << "\t*** Stop Report ***" << std::endl << std::endl;
    (*stop_iter)->Report(std::cout);
  }
  
  for (int i = 0; i < rounds; i++) {
    std::cout << "/*\n *\n * Generation #" << (i+1) << "\n *\n*/" << std::endl;
  
    total_generated += generator.GeneratePassengers();
  
    std::cout << "/*\n *\n * Report\n *\n*/" << std::endl;
  
    for (std::list<Stop *>::iterator stop_iter = my_stops.begin(); stop_iter != my_stops.end(); stop_iter++) {
      (*stop_iter)->Update();
      std::cout  << std::endl << "\t*** Stop Report ***" << std::endl << std::endl;
      (*stop_iter)->Report(std::cout);
    }
    
    std::cout << std::endl << std::endl;
  }
  
  
  
  std::cout << "*\n*\n*\n*\n*\t PASSENGERS CREATED *\n*\n*\n*\n*\n" << std::endl;
  std::cout << total_generated << std::endl;
  
  return 0;
}