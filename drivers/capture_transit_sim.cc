#include <ctime>
#include <iostream>
#include <random>
#include <fstream>
#include "local_simulator.h"

int main(int argc, char* argv[]) {
  using namespace std;
  if (argc != 2) {
    perror("right amount of arguments not provided, expected 1");
  }

  ofstream of_ptr;
  of_ptr.open(argv[1],std::ios_base::app);
  //  put output in file
  if (of_ptr.is_open()){
    int rounds = 50; //Number of rounds of generation to simulate in test

    srand((long)time(NULL)); //Seed the random number generator...

    LocalSimulator my_sim(argv[1]);

    of_ptr << "/*************************" << endl << endl;
    of_ptr << "         STARTING" << endl;
    of_ptr << "        SIMULATION" << endl;
    of_ptr << "*************************/" << endl;

    my_sim.Start();

    of_ptr << "/*************************" << endl << endl;
    of_ptr << "           BEGIN" << endl;
    of_ptr << "          UPDATING" << endl;
    of_ptr << "*************************/" << endl;

    for (int i = 0; i < rounds; i++) {
  	  my_sim.Update();
    }

    of_ptr << "/*************************" << endl << endl;
    of_ptr << "        SIMULATION" << endl;
    of_ptr << "         COMPLETE" << endl;
    of_ptr << "*************************/" << endl;
    of_ptr.close();
  }

  return 0;
}
