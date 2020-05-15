#include <iostream>
#include <random>
#include <ctime>

#include "passenger.h"
#include "passenger_factory.h"

int main() {
  
  srand((long)time(NULL)); //Seed the random number generator...
  
  std::cout << "Let's begin..." << std::endl;
  int current = 1;
  int end = 20;
  Passenger * tmp = NULL;

  std::cout << "Entering loop..." << std::endl;

  for (int i = 0; i < 100; i++) {
    std::cout << "Making Passenger #" << i << std::endl;
    tmp = PassengerFactory::Generate(current, end);
    std::cout << "Reporting: " << std::endl;
    tmp->Report(std::cout);
    
    delete tmp;
  }

  std::cout << "After loop..." << std::endl;
  
  return 0;
}