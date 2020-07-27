/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <random>
#include <ctime>

#include "./passenger_generator.h"
#include "./stop.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  // forward declaration
/**
 * @brief Child class of the passenger generator. Implements a generate
 * passenger function that creates passengers at each stop.
 */
class RandomPassengerGenerator : public PassengerGenerator{
 public:
 /**
   * @brief Constructor of the RandomPassengerGenerator
   *
   * @param[in] std::list<double> probabilities, chances of passengers getting generated. Out of 1.0.
   * @param[in] std::list<Stop *> stops, list of stops that passengers will get generated into.
   */
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
    * @brief Function to generate passengers at each stop.
    *
    * @return numReturns the total number of passengers generated
    */
  int GeneratePassengers() override;

 private:
 /**
   * @brief Random number generator
   */
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
