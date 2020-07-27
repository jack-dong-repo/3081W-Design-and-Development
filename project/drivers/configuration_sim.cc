/**
 * @file configuration_sim.cc
 *
 * @copyright Jack Dong, All rights reserved.
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>

#include "src/config_manager.h"
#include "src/configuration_simulator.h"
#include "src/config_sim_helper.h"
/*******************************************************************************
* Main method
******************************************************************************/
int main(int argc, char**argv) {
  std::cout << std::endl;
  std::cout << "Usage: ./build/bin/config_sim <config_filename> " <<
               "<simulation_length> <time_between_busses>" << std::endl;
  std::cout << std::endl;

  ArgumentHandling(argc, argv);

  // initialize config_manager, configuration_simulator
  ConfigManager* my_config_manager = new ConfigManager();
  my_config_manager->ReadConfig(file_name);
  ConfigurationSimulator my_config_sim(my_config_manager);

  std::vector<int> busStartTimings;
  busStartTimings.push_back(BUS_START_TIMINGS);

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;

  my_config_sim.Start(busStartTimings, NUM_TIME_STEP);

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  for (int i = 0; i < sim_length; i++) {
    my_config_sim.Update();
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;

  return 0;
}
