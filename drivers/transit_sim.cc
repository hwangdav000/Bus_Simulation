#include <ctime>
#include <iostream>
#include <random>

#include "local_simulator.h"

int main() {

  int rounds = 35; //Number of rounds of generation to simulate in test

  srand((long)time(NULL)); //Seed the random number generator...

  LocalSimulator my_sim("");

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;

  my_sim.Start();

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  for (int i = 0; i < rounds; i++) {
	  my_sim.Update();
    //std::cout << "why isnt this updating" << std::endl;
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;


  return 0;
}
