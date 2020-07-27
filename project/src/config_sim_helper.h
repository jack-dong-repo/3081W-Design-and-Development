/**
 * @file config_sim_helper.h
 *
 * @copyright Jack Dong, All rights reserved.
 */
#ifndef SRC_CONFIG_SIM_HELPER_H_
#define SRC_CONFIG_SIM_HELPER_H_
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
/*******************************************************************************
 * Global Variables
 ******************************************************************************/
std::ifstream in_file;
std::string file_name;
int sim_length = 0;
int bus_length = 0;
int BUS_START_TIMINGS = 100;  // Default value
int NUM_TIME_STEP = 10;  // Default value
/*******************************************************************************
 * Method declarations
 ******************************************************************************/
static void Arg1();  // one command line argument
static void Arg2(char*);  // two command line arguments
static void Arg3(char*, int);  // three command line arguments
static void Arg4(char*, int, int);  // four command line arguments
static void GetSimulationLength();  // gets total simulation length
static void GetBusDeployTime();  // gets time between bus deployment
static void GetYesNoAns(bool);  // gets yes or no answer
static void CheckFile(char*);  // checks if file is openable
static void ArgumentHandling(int, char**);  // main parameter handling method
/*******************************************************************************
 * Method definitions
 ******************************************************************************/
static void GetSimulationLength() {
  // only accepts positive integers
  while (sim_length <= 0) {
    std::cout << "Enter length of time simulation: " << std::endl;
    std::cin >> sim_length;
  }
}

static void GetYesNoAns(bool ask_continue) {
  // accounts for unexpected user inputs, 128 is arbitrary
  char * ans = static_cast<char*>(malloc(128));
  std::cin >> ans;

  // only accepts "y" or "n" answers
  while (strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0) {
  // for context use only, some prompts need the following to provide
  // context to users
    if (ask_continue) {
      std::cout << "Continue? (y/n)" << std::endl;
    } else {
      std::cout << "Enter only (y/n)" << std::endl;
    }
    std::cin >> ans;

    if (strcmp(ans, "y") == 0) {
      break;
    } else if (strcmp(ans, "n") == 0) {
      free(ans);
      exit(1);
    }
  }
  // needed outside while loop when user answers "n" right away
  if (strcmp(ans, "n") == 0) {
    free(ans);
    exit(1);
  }
  free(ans);
}

static void CheckFile(char * filename) {
  // string and char array data type handling
  char buffer[128];
  char* cursor = buffer;
  cursor += snprintf(cursor, sizeof("./config/")+10, "./config/");
  cursor += snprintf(cursor, sizeof(filename)+10, "%s", filename);

  // try to open "./config/filename"
  in_file.open(buffer);

  if (!in_file) {
    std::cout << "Cannot open file: " << filename << std::endl;
    std::cout << "Default to config/config.txt? (y/n)" << std::endl;
    GetYesNoAns(false);
    // if okay with using default file, set file_name to config.txt
    file_name = "config.txt";
  } else {
    // user inputted file is openable
    file_name = filename;
  }
  in_file.close();
}

static void GetBusDeployTime() {
  // only allows positive integers
  while (bus_length <= 0) {
    std::cout << "Enter length of time between bus deployment: " << std::endl;
    std::cin >> bus_length;
  }
}

static void Arg1() {
  // no arguments entered - ask if config.txt works and get times
  std::cout << "Default to config/config.txt? (y/n)" << std::endl << std::endl;
  GetYesNoAns(true);
  file_name = "config.txt";
  GetSimulationLength();
  GetBusDeployTime();
}

static void Arg2(char * filename) {
  // checks file then asks for times
  CheckFile(filename);
  GetSimulationLength();
  GetBusDeployTime();
}

static void Arg3(char * filename, int SimLength) {
  // checks filename, checks if simulation_time is proper,
  // asks for bus deployment time
  CheckFile(filename);
  sim_length = SimLength;
  GetSimulationLength();
  GetBusDeployTime();
}

static void Arg4(char * filename, int SimLength, int BusLength) {
  // checks if filename can be opened, checks if simlength and buslength
  // are positive integers
  CheckFile(filename);
  sim_length = SimLength;
  GetSimulationLength();
  bus_length = BusLength;
  GetBusDeployTime();
}

static void ArgumentHandling(int argc, char** argv) {
  // directs argc and argv to its corresponding argument methods
  if (argc == 1) {
    std::cout << "No file specified." << std::endl;
    Arg1();
  } else if (argc == 2) {
    Arg2(argv[1]);
  } else if (argc == 3) {
    Arg3(argv[1], atoi(argv[2]));
  } else if (argc == 4) {
    Arg4(argv[1], atoi(argv[2]), atoi(argv[3]));
  } else {
    std::cout << "Please follow usage guidelines." << std::endl;
    std::cout << "Usage: ./build/bin/config_sim <config_filename> " <<
            "<simulation_length> <time_between_busses>" << std::endl;
    exit(1);
  }
}

#endif  // SRC_CONFIG_SIM_HELPER_H_
