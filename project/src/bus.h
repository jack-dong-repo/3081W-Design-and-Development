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
#include <iostream>
#include <list>
#include <string>

#include "./passenger.h"
#include "./route.h"
#include "./stop.h"
#include "./data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
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
  * @param[in] name, name of the bus
  * @param[in] out, outbound route
  * @param[in] in, inbound route
  * @param[in] capacity, Max capacity is 60 by default
  * @param[in] speed, Speed is 1 by default
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
 /**
  * @brief Loads a passenger onto the bus
  *
  * @param[in] passenger pointer
  * @return true if passenger got on bus successfully, false otherwise
  */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
   * @brief Loads a passenger off the bus
   *
   * @param[in] passenger pointer
   */
  void UnloadPassengers(Stop *);
  /**
   * @brief [NEW FUNCTION] Move the bus to its next stop
   *
   * @return true if successfuly moved to next stop, false otherwise
   */
  bool Move();
  /**
   * @brief Updates bus attributes
   */
  void Update();
  /**
   * @brief Outputs report of bus metrics
   */
  void Report(std::ostream&);
  /**
   * @brief Status of bus is at the end of route
   *
   * @return true if bus is at the end, false otherwise
   */
  bool IsTripComplete();
  /**
   * @brief [NEW FUNCTION] Checks which route bus is currently on
   *
   * @return true if on incoming route, false if on outgoing route
   */
  bool IsIncomingRoute();
  /**
   * @brief [NEW FUNCTION] When bus reaches the end of its current route,
   * change the route to the other one
   *
   */
  void ChangeRoute();
  /**
   * @brief [NEW FUNCTION] Get the stop ID of the bus is going to
   *
   * @return integer stop ID
   */
  int GetCurrentStopId() const;
  /**
   * @brief Update bus metrics including geo coordinates, current capcacity,
   * and max capcaity.
   */
  void UpdateBusData();
  /**
   * @brief Return bus data struct that contains information on geo coordinates,
   * passenger capcaity, and number of passengers.
   *
   * @return BusData struct
   */
  BusData GetBusData();
  /**
   * @brief Return name of the bus
   *
   * @return String data type of the bus name
   */
  std::string GetName() const;
  /**
   * @brief Return current route's destination stop
   *
   * @return Stop object pointer to next destination stop
   */
  Stop * GetNextStop();
  /**
   * @brief Return current number of passengers on bus
   *
   * @return size_t number of current number of passengers on bus
   */
  size_t GetNumPassengers();
  /**
   * @brief Returns max capacity of bus
   *
   * @return int data type of max bus capacity
   */
  int GetCapacity();
  /**
   * @brief Calculates and returns the position that the bus should move to.
   * Bus will calculate the midpoint between two stops, or the destination stop
   * if the bus is at a stop
   *
   * @return Position struct that contains longtitude and latitude coordinates
   */
  Position GetUpdateCoordinates();
  /**
   * @brief Returns the previous stop's geo location coordinates. Helper method
   * of GetUpdateCoordinates()
   *
   * @return Position struct that contains longtitude and latitude coordinates
   */
  Position GetLastStopPosition();
  /**
   * @brief Unloads all passengers. Only called when bus is at the last stop
   *
   * @param[in] Stop * stop, the last stop on the route
   *
   */
  void UnloadAllPassengers(Stop *);

 private:
   /**
    * @brief list of passengers on the bus
    */
  std::list<Passenger *> passengers_;
  /**
   * @brief total maximum number of passengers allowed on bus
   */
  int passenger_max_capacity_;
  /**
   * @brief Name of the bus
   */
  std::string name_;
  /**
   * @brief could also be called "distance travelled in one time step
   */
  double speed_;
  /**
   * @brief Outgoing route
   */
  Route * outgoing_route_;
  /**
   * @brief Incoming route
   */
  Route * incoming_route_;
  /**
   * @brief Distance remaining until next stop.
   *  when negative?, unload/load procedure occurs AND next stop set
   */
  double distance_remaining_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;

  Route * current_route_;
  /**
   * @brief Contains information on geo coordinates, passenger capcaity,
   * and number of passengers.
   */
  BusData bus_data_;
};
#endif  // SRC_BUS_H_
