/**
 * @file r_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_R_LOCAL_SIMULATOR_H_
#define SRC_R_LOCAL_SIMULATOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "src/simulator.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class rLocalSimulator : public Simulator {
 public:
    /*
     * @brief Starts the local simulator
     */
    bool Start() override;
    /*
     * @brief Updates all objects within simulation.
     */
    bool Update() override;

 private:
    /*
     * @brief Number of bus counts
     */
    std::vector<int> bus_counters_;
    /*
     * @brief Time each bus deploys from each other
     */
    std::vector<int> bus_start_timings_;
    /*
     * @brief Time since last bus was generated
     */
    std::vector<int> time_since_last_bus_generation_;
    /*
     * @brief Total simulation time since Start() was called
     */
    int simulation_time_elapsed_;
};
#endif  // SRC_R_LOCAL_SIMULATOR_H_
