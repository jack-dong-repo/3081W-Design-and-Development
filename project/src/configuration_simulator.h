/**
 * @configuration_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONFIGURATION_SIMULATOR_H_
#define SRC_CONFIGURATION_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>

#include "./config_manager.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Route;
class Bus;
class Stop;
/**
 * @brief Main class of the configuration simulator. Has ability to start and
 * update the simulation. Contains configuration manager object, vector of
 * time between each bus start times and time since last bus, time steps,
 * tracks simulation time, routes and buses.
 */
class ConfigurationSimulator {
 public:
   /**
    * @brief Constructor of ConfigurationSimulator.
    *
    * @param[in] ConfigManager pointer
    */
  explicit ConfigurationSimulator(ConfigManager*);
  /**
   * @brief Destructor of ConfigurationSimulator. Deletes configuration manager.
   */
  ~ConfigurationSimulator();
  /**
   * @brief Starts the simulation. Initializes simulation time to 0 and
   * updates routes to initial data.
   *
   * @param[in] std::vector<int>&, vector of busStartTimings
   * @param[in] const int&, constant number of time steps
   */
  void Start(const std::vector<int>&, const int&);
  /**
   * @brief Starts the simulation. Initializes simulation time to 0 and
   * updates routes to initial data through Report route data structs and
   * Update().
   *
   * @param[in] std::vector<int>& busStartTimings_, vector of busStartTimings
   * @param[in] const int&, constant number of time steps
   */
  void Update();

 private:
   /**
    * @brief Pointer to config manager instance. This helps read in data to
    * create routes and buses.
    */
  ConfigManager* configManager_;
  /**
   * @brief Vector of times when busses get deployed
   */
  std::vector<int> busStartTimings_;
  /**
   * @brief Vector of times between each busses' deployment
   */
  std::vector<int> timeSinceLastBus_;
  /**
   * @brief How often update gets ran
   */
  int numTimeSteps_;
  /**
   * @brief Time since simulation started
   */
  int simulationTimeElapsed_;
  /**
   * @brief Vector of routes
   */
  std::vector<Route *> prototypeRoutes_;
  /**
   * @brief Vector of busses
   */
  std::vector<Bus *> busses_;
  /**
   * @brief Bus Id
   */
  int busId = 1000;
};

#endif  // SRC_CONFIGURATION_SIMULATOR_H_
