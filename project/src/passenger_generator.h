/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "./passenger_factory.h"
#include "./stop.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Stop;  // forward declaration
/**
 * @brief Abstract class that contains list of probabilities and stops.
 * Probability indicates the chance a passenger is generated at that stop.
 */
class PassengerGenerator {
 public:
   /**
    * @brief Constructor for list of generation of probablilties and stops.
    *
    * @param[in] std::list<double>, list of probabilities that a passenger is generated
    * at a given stop
    * @param[in] std::list<Stop *>, list of stops where each index indicates a unique stop
    */
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  /**
   * @brief Makes the class abstract, cannot instantiate and forces subclass override.
   */
  virtual int GeneratePassengers() = 0;  // pure virtual

 protected:
   /**
    * @brief Probability list
    */
  std::list<double> generation_probabilities_;
  /**
   * @brief List of stops
   */
  std::list<Stop *> stops_;
  /**
   * @brief Instance of passenger factory
   */
  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
