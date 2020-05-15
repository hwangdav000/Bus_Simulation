/**
* @file configuration_sim.cc
*
* @copyright 2019 3081 Staff, All rights reserved.
*/
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <random>


#include "src/config_manager.h"
#include "src/configuration_simulator.h"

bool is_number(std::string);
//  check if input is digit or not
bool is_number(std::string str) {
  std::string::const_iterator it = str.begin();
  while (it != str.end()) {
    //  check if it is char or number
    if (!(std::isdigit(*it))) {
      return false;
    }
    it++;
  }
  return true;
}

//  config sim should exit gracefully (run with 0)
//  in case of error with
//  1. config txt not specified
//  2. config txt is not correct
int main(int argc, char **argv) {
  int length_sim_ = 50;
  bool error1 = false;
  bool error2 = false;
  bool error3 = false;
  bool error4 = false;
  bool error5 = false;
  std::string config_name_ = "config.txt";

  //  subject to change
  int bus_time_s_ = 10;
  ConfigManager* config_m_;
  //  check arguments for configuration sim
  // as follows exec, config file, number_of_turns only need two
  //  overwrite length of sim
  //  only executable is run
  if (argc == 1) {
    error1 = true;
  }
  std::string check;
  if (argv[2] != NULL) {
    check = argv[2];
  }
  //  get length of sim
  if (argc >= 3) {
    if (is_number(check)) {
      length_sim_ = atoi(argv[2]);
    } else {
      error2 = true;
    }
  }

  //  get time of when buses is built
  std::string check2;
  if (argv[3] != NULL) {
    check2 = argv[3];
  }
  if (argc >= 4) {
    if (is_number(check2)) {
      bus_time_s_ = atoi(argv[3]);
    } else {
      error3 = true;
    }
  }
  //  over 4 arguments (excluding exec 3)
  if (argc > 4) {
    error4 = true;
  }

  //  check to make sure string not null
  std::string check3;
  if (argv[1] != NULL) {
    check3 = argv[1];
  }
  //  check if config txt is in config
  //  assumption- that all txt in config
  //  works correctly
  if (FILE *file = fopen(("config/" + check3).c_str(), "r")) {
    //  txt found in config
    fclose(file);
    //  check that check3 is not empty
    if (!(check3 == "")) {
      config_name_ = check3;
    }
  } else {
    error5 = true;
  }

  //  put in configmanager
  config_m_ = new ConfigManager();
  config_m_ -> ReadConfig(config_name_);

  //  create configuration simulator
  //  takes in prototype routes
  ConfigSimulator my_sim(config_m_, bus_time_s_);
  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;
  my_sim.Start();
  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;
  for (int i = 0 ; i < length_sim_; i++) {
    my_sim.Update();
  }

  //  run error messages here so visible to user
  if (error1) {
    std::cout << "/*************************" << std::endl << std::endl;
    std::cout << "         CONFIG TXT" << std::endl;
    std::cout << "        NOT PROVIDED" << std::endl;
    std::cout << "*************************/" << std::endl;
  }
  if (error2) {
    std::cout << "/*************************" << std::endl << std::endl;
    std::cout << "         LENGTH OF SIM" << std::endl;
    std::cout << "        INPUT INCORRECT" << std::endl;
    std::cout << "*************************/" << std::endl;
  }
  if (error3) {
    std::cout << "/*************************" << std::endl << std::endl;
    std::cout << "         FIRST INITIAL BUS" << std::endl;
    std::cout << "        TIME INCORRECT" << std::endl;
    std::cout << "*************************/" << std::endl;
  }
  if (error4) {
    std::cout << "/*************************" << std::endl << std::endl;
    std::cout << "         ARGS" << std::endl;
    std::cout << "        OVER 3" << std::endl;
    std::cout << "*************************/" << std::endl;
  }
  if (error5) {
    std::cout << "/*************************" << std::endl << std::endl;
    std::cout << "         CONFIG TXT" << std::endl;
    std::cout << "        INCORRECT" << std::endl;
    std::cout << "*************************/" << std::endl;
  }
  return 0;
}
