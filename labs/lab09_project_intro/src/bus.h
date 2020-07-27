/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "passenger.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for bus.
 *
 * Contains metrics of a bus object
 */

class Bus {
 public:
   /**
    * @brief Constructor for passenger.
    *
    * @param[in] capacity, Max capacity is 60 by default
    * @param[in] speed, Speed is 1 by default
    */
  explicit Bus(int capacity = 60, double speed = 1);
  /**
   * @brief Loads a passenger onto the buss
   *
   * @param[in] passenger pointer
   */
  bool LoadPassenger(Passenger *);  //  returning revenue delta
 private:
   /**
    * @brief The bus's max capacity
    */
  int passenger_max_capacity_;
  /**
   * @brief Could also be called "distance travelled in one time step
   */
  double speed_;
};
#endif  // SRC_BUS_H_
