/**
 * @file passenger_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include <random>
#include <string>

#include "src/passenger_factory.h"

std::random_device dev;
std::mt19937 e(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000);

// Here I will create an array of prefixes to help generate names.
// I am banking on multiplication to ensure a large number of names
// by using 7 prefixes and 20 stems, and 16 suffixes I should be able to
// create about 7 * 20 * 16 = 2240 names out of 312 bytes of data (In my earlier
// example from the forum I used this code to generate male and female names,
// but here I combined them).

<<<<<<< HEAD
static const char std::string NamePrefixArray[] = {
=======
static const char* NamePrefixArray[7] = {
>>>>>>> 520a132bbf674a0d33823e9100b1b96233ec9f4c
"",  // who said we need to add a prefix?
"bel",  // lets say that means "the good"
"nar",  // "The not so good as Bel"
"xan",  //" The evil"
"bell",  // "the good"
"natr",  // "the neutral/natral"
"ev",  // Man am I original
};

<<<<<<< HEAD
static const char std::string NameSuffixArray[] = {
=======
static const char* NameSuffixArray[16] = {
>>>>>>> 520a132bbf674a0d33823e9100b1b96233ec9f4c
"", "us", "ix", "ox", "ith",
"ath", "um", "ator", "or", "axia",
"imus", "ais", "itur", "orex", "o",
"y"
};

<<<<<<< HEAD
static const char std::string NameStemsArray[] = {
=======
static const char* NameStemsArray[20] = {
>>>>>>> 520a132bbf674a0d33823e9100b1b96233ec9f4c
"adur", "aes", "anim", "apoll", "imac",
"educ", "equis", "extr", "guius", "hann",
"equi", "amora", "hum", "iace", "ille",
"inept", "iuv", "obe", "ocul", "orbis"
};

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// Code for name generation adapted from:
// https://www.dreamincode.net/forums/topic/27024-data-modeling-for-games-in-c-part-ii/
Passenger * PassengerFactory::Generate(int curr_stop, int last_stop) {
  std::string new_name = NameGeneration();

  // common use of random integer generation to determine
  // what stop the passenger will depart the bus

  int destination = (dist(e) % (last_stop - curr_stop)) + curr_stop + 1;
  return new Passenger(destination, new_name);
}

std::string PassengerFactory::NameGeneration() {
  // assume rand is seeded
  std::string name = std::string(NamePrefixArray[(dist(e) % 7)])
                     + std::string(NameStemsArray[(dist(e) % 20)])
                     + std::string(NameSuffixArray[(dist(e) % 16)]);
  name[0] = toupper(name[0]);  // don't forget to capitalize!
  return name;
}
