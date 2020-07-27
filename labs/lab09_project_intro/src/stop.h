/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>

#include "src/passenger.h"
#include "src/bus.h"

class Bus;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for passenger.
 *
 * Contains metrics of passengers of the bus system
 */
class Stop {
 public:
   /**
    * @brief Constructor for Stop class.
    *
    * @param[in] stop_ID, the stop ID
    * @param[in] longitude_, longitude is 44.973723 by default
    * @param[in] latitude_, latitude is -93.235365 by default
    *
    */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  /**
   * @brief Removes passengers from stop and onto a bus
   */
  void LoadPassengers(Bus *);
  /**
   * @brief Addspassengers to the stop (from the generator)
   */
  void AddPassengers(Passenger *);
  /**
   * @brief Gets Stop ID
   *
   * @return Returns Stop ID
   */
  int GetId() const;
  /**
   * @brief Prints report of stop details and metrics
   */
  void Report() const;
 private:
   /**
    * @brief Stop ID, each stop has a unique ID
    */
  int id_;
  /**
   * @brief List of passegers
   */
  std::list<Passenger *> passengers_;
  /**
   * @brief Longitude of stop location
   */
  double longitude_;
  /**
   * @brief Latitude of stop location
   */
  double latitude_;
};
#endif  // SRC_STOP_H_
