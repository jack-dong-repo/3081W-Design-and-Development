/**
 * @file data_structs.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_DATA_STRUCTS_H_
#define SRC_DATA_STRUCTS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>

/**
 * @brief Position struct. Contains longtitude and latitude coordinates
 *
 * @param[in] x, longtitude
 * @param[in] y, latittude
 */
struct Position {
    Position() : x(0), y(0) {}
    float x;
    float y;
};

/**
 * @brief Bus struct. Contains bus metrics at a given point. Contains the
 * geo location coordinates that get updated constantly.
 *
 * @param[in] string::id, name of the bus
 * @param[in] int num_passengers, current number of passengers
 * @param[in] int capacity, maximum capacity of bus
 */
struct BusData {
    BusData() : id(""), position(Position()), num_passengers(0), capacity(0) {}
    std::string id;  // some unique identifier for the bus
    Position position;  // long lat position of bus
    int num_passengers;
    int capacity;
};

/**
 * @brief Stop struct. Contains stop metrics at a given point. Contains the
 * geo location coordinate and number of people.
 *
 * @param[in] string::id, name of the stop
 * @param[in] Position position, location of the stop
 * @param[in] int num_people, number of people at the stop
 */
struct StopData {
    StopData() : id(""), position(Position()), num_people(0) {}
    std::string id;  // some unique identifier for the stop
    Position position;  // long lat position of bus
    int num_people;
};

/**
 * @brief Route struct. Contains route metrics at a given point. Contains the
 * vector of stops structs.
 *
 * @param[in] string::id, name of the route
 * @param[in] std::vector<StopData> stops, vector of stop structs
 */
struct RouteData {
    RouteData() : id(""), stops(std::vector<StopData>(0)) {}
    std::string id;  // some unique identifier for the route
    std::vector<StopData> stops;
};

#endif  // SRC_DATA_STRUCTS_H_
