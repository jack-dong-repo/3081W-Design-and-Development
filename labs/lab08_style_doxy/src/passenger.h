/*!
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for passenger.
 *
 * Contains metrics of passengers of the bus system
 */

class Passenger {  // : public Reporter {
 public:
   /**
    * @brief Constructor for passenger.
    *
    * @param[in] destination_stop_id, Destination Stop ID
    * @param[in] name, Name
    */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
   * @brief Updates time spent at bus stop
   */
  void Update();
  /**
   * @brief Change passenger's status that they're on the bus.
   */
  void GetOnBus();
  /**
   * @brief Returns the total time waiting for bus.
   *
   * @return Int variable indicating total time waiting for bus.
   */
  int GetTotalWait() const;
  /**
   * @brief Returns if passenger is on bus or not.
   *
   * @return FALSE if not on bus, TRUE if on bus
   */
  bool IsOnBus() const;
  /**
   * @brief Returns destintation ID
   *
   * @return Int variable indicating destination
   */
  int GetDestination() const;
  /**
   * @brief Generate report containing passenger details
   */
  void Report() const;

 private:
   /**
    * @brief Name of the passenger.
    */
  std::string name_;
  /**
   * @brief Stop ID of where passenger wants to go.
   */
  int destination_stop_id_;
  /**
   * @brief Total time at the stop
   */
  int wait_at_stop_;
  /**
   * @brief Total time on the bus
   */
  int time_on_bus_;
  /**
   * @brief global count of passengers, used to set ID for new instances
   */
  int id_;
  static int count_;
};
#endif  // SRC_PASSENGER_H_
