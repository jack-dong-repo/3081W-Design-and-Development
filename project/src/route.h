/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>
#include <string>
#include <vector>

#include "./passenger_generator.h"
#include "./stop.h"
#include "./data_structs.h"

class PassengerGenerator;
class Stop;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
  * @brief The main class for Route.
  *
  * Contains Route attributes. Has a name, list of stops, distances between
  * stops, and a passenger generator.
  */
class Route {
 public:
   /**
     * @brief Constructor for Stop class.
     *
     * @param[in] name, name of the route
     * @param[in] stops, a list to a pointer of stops
     * @param[in] distances, list of distances between stops
     * @param[in] num_stops, total number of stops
     * @param[in] pass_gen, passenger generator
     */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
                                                      PassengerGenerator *);
  /**
   * @brief Clone exact copy of the route
   *
   * @return Route object
   */
  Route * Clone();
  /**
    * @brief Updates all the stops within route
    */
  void Update();
  /**
    * @brief Returns current status of variables
    */
  void Report(std::ostream&);
  /**
    * @brief Returns if bus reaches end of route
    *
    * @return Returns true if at the end, false otherwise
    */
  bool IsAtEnd();
  /**
    * @brief Change destination_stop_ to next stop
    */
  void NextStop();
  /**
    * @brief Get pointer to next stop
    *
    * @return Stop class pointer to the next stop
    */
  Stop * GetDestinationStop() const;
  /**
    * @brief Get total route distance
    *
    * @return Total route distance
    */
  double GetTotalRouteDistance() const;
  /**
    * @brief Get Distance of the next stop
    *
    * @return Next stop distance, double
    */
  double GetNextStopDistance() const;
  /**
    * @brief Return position of previous stop
    *
    * @return Position struct containing longtitude and latittude
    */
  Position GetPrevCoordinates();
  /**
    * @brief Return position of destination stop
    *
    * @return Position struct containing longtitude and latittude
    */
  Position GetDestCoordinates();
  /**
    * @brief Return name of the route
    *
    * @return String name_
    */
  std::string GetName();
  /**
    * @brief Return stops list within route
    *
    * @return list of stop pointers
    */
  std::list<Stop *> GetStops();
  /**
    * @brief Updates the data within Route including stops vector and name.
    * Mainly used when initializing route.
    */
  void UpdateRouteData();
  /**
    * @brief Returns route data struct
    *
    * @return Returns route data struct
    */
  RouteData GetRouteData();
  /**
    * @brief Obtain vector of stop structs
    *
    * @return vector of stop structs
    */
  std::vector<StopData> GetStopStructVect();
  /**
    * @brief Return previous stop's position
    *
    * @return Return previous stop's position
    */
  Position GetLastStopPosition();

 private:
   /**
     * @brief generates passengers on its route
     *
     * @return Total number of generated passengers
     */
  int GenerateNewPassengers();
  /**
    * @brief Instance of passenger generator to create
    * passengers at each stop. Gets called in constructor
    */
  PassengerGenerator * generator_;
  /**
    * @brief List of stops in order
    */
  std::list<Stop *> stops_;
  /**
    * @brief List of distances between the ith and (i+1)th stop.
    * length = num_stops_ - 1
    */
  std::list<double> distances_between_;
  /**
    * @brief name of the route
    */
  std::string name_;
  /**
    * @brief Total number of stops
    */
  int num_stops_;
  /**
    * @brief always starts at zero, no init needed
    */
  int destination_stop_index_;
  /**
    * @brief Stop class of the next stop
    */
  Stop * destination_stop_;
  /**
    * @brief derived data - total distance travelled on route
    */
  double trip_time_;
  /**
    * @brief Route Struct. Contains name of route and vector of stop structs
    */
  RouteData route_data_;
};

#endif  // SRC_ROUTE_H_
