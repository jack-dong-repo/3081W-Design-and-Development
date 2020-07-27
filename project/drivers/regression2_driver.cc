/**
 * @r_local_simulator2.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <string>

#include "./r_local_simulator2.h"
/*******************************************************************************
* Main method
******************************************************************************/
int main() {
  int rounds = 50;  // Number of rounds of generation to simulate in test

  // Seed the random number generator with the same seed every time!
  srand((__int16_t)1);

  rLocalSimulator2 my_sim;

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
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;

  return 0;
}
