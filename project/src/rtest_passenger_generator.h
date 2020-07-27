/**
 * @file rtest_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RTEST_PASSENGER_GENERATOR_H_
#define SRC_RTEST_PASSENGER_GENERATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  // forward declaration

class RtestPassengerGenerator : public PassengerGenerator{
 public:
 /**
   * @brief Regression testing passenger generator constructor
   *
   * @param[in] std::list<double> probabilities
   * @param[in] std::list<Stop *> stops
   */
  RtestPassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
    * @brief Generates passengers within each stop
    *
    * @return Returns the total number of passengers
    */
  int GeneratePassengers() override;

 private:
   /**
     * @brief Random seed
     */
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RTEST_PASSENGER_GENERATOR_H_
