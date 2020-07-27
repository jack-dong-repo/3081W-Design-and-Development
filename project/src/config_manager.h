/**
 * @config_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Route;
/**
 * @brief Helper class for Configuration Simulator. Reads in text file to
 * generate routes for simulation.
 */
class ConfigManager {
 public:
   /**
    * @brief Constructor for confiuration manager. Does not take in any
    * parameters. Initalizes route vector.
    */
  ConfigManager();
  /**
   * @brief Destructor for confiuration manager. Assigns null pointers to
   * all indices within route vector
   */
  ~ConfigManager();
  /**
   * @brief Takes in string filename that contains information on stops and
   * routes. Generate routes and stop objects to be stored in route vector.
   *
   * @param[in] filename, takes in the name of file only. No path included.
   */
  void ReadConfig(const std::string filename);
  /**
   * @brief Returns the route vector
   *
   * @return a vector of Route pointer objects
   */
  std::vector<Route *> GetRoutes() const { return routes; }

 private:
   /**
    * @brief Route vector
    */
  std::vector<Route *> routes;
};

#endif  // SRC_CONFIG_MANAGER_H_
