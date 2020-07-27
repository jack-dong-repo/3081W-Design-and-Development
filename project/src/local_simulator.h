/**
 * @file local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_LOCAL_SIMULATOR_H_
#define SRC_LOCAL_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include "./simulator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
  * @brief Class that provides start and update function implementation on
  * abstract class Simulator. Can simulation the bus system.
  */
class LocalSimulator : public Simulator {
 public:
 /**
   * @brief Starts simulation timer. Generates passengers
   *
   * @return returns true if simulation successfuly starts, false otherwise
   */
  bool Start() override;
  /**
   * @brief Updates simulation timer, and passengers' timer
   *
   * @return returns true if simulation successfuly updates, false otherwise
   */
  bool Update() override;

 private:
   /**
    * @brief Helps track busses to update and report on them
    */
  std::vector<int> bus_counters_;
  /**
   * @brief Times of when busses start deployment
   */
  std::vector<int> bus_start_timings_;
  /**
   * @brief Times of when previous bus was deployed
   */
  std::vector<int> time_since_last_bus_generation_;
  /**
   * @brief Simulation timer
   */
  int simulation_time_elapsed_;
};

#endif  // SRC_LOCAL_SIMULATOR_H_
