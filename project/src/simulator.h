/**
 * @file simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_SIMULATOR_H_
#define SRC_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <vector>

#include "./bus.h"
#include "./stop.h"
#include "./route.h"
#include "./passenger_generator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief Abstract class Simulator
  */
class Simulator {
 public:
   /**
    * @brief Starts simulation
    */
  virtual bool Start() = 0;
  /**
   * @brief Bus and stop list will be iterated over to update
   */
  virtual bool Update() = 0;

 protected:
  /**
   * @brief List of active buses
   * Buses can leave scope
   */
  std::list<Bus *> active_buses_;
  /**
   * @brief List of all stops
   */
  std::list<Stop *> all_stops_;
  /**
   * @brief prototype_routes and distance lists will be accessed directly
   * list is not efficient at direct selection by index
   * routes for copying on bus creation
   */
  std::vector<Route *> prototype_routes_;
  /**
   * @brief index i is distance between stop i and i+1
   */
  std::vector<double *> distance_between_sets_;
  /**
   * @brief list of generated passengers
   */
  std::vector<PassengerGenerator *> passenger_generators_;
  // std::vector<std:list<double>> passenger_generation_probability_lists;
};

#endif  // SRC_SIMULATOR_H_
