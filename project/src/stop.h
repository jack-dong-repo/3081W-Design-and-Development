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

#include "./bus.h"
#include "./passenger.h"
#include "./data_structs.h"

class Bus;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
  * @brief The main class for passenger.
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
    * @brief Gets Stop ID
    *
    * @return Returns Stop ID
    */
    int GetId();
    /**
     * @brief Addspassengers to the stop (from the generator)
     */
    int AddPassengers(Passenger *);
    /**
     * @brief Increments all passengers within stop's times
     */
    void Update();
    /**
     * @brief Prints report of stop details and metrics
     */
    void Report(std::ostream&) const;
    /**
     * @brief Prints report of stop details and metrics
     */
    int LoadPassengers(Bus *);
    /**
     * @brief Return geo coordinates of stop
     *
     * @return Position struct of stop location
     */
    Position GetCoordinates();
    /**
     * @brief Return stop struct that contains its metrics, including the
     * name, location, and number of people at the stop.
     *
     * @return StopData struct
     */
    StopData GetStopData();
    /**
     * @brief Return integer of number of people at stop
     *
     * @return integer of number of people at stop
     */
    int GetPassengerCount();

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
    // derived information - not needed depending on passengers_
    // data structure implementation?
    // int passengers_present_;
};

#endif  // SRC_STOP_H_
