/**
 * @file bus.cc
 *
 * @copyright Jack Dong, All rights reserved.
 */
#include <iostream>
#include <string>
#include <cmath>

#include "src/bus.h"
#include "src/data_structs.h"

Bus::Bus(std::string name, Route *out, Route *in,
                    int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  current_route_ = out;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
}

bool Bus::LoadPassenger(Passenger * new_passenger) {
  // bus is at capcacity
  if ((signed int)passengers_.size() >= passenger_max_capacity_) {
    return false;
  }

  // change status within passenger and add person to bus list
  new_passenger->GetOnBus();
  passengers_.push_back(new_passenger);
  return true;
}

void Bus::UnloadAllPassengers(Stop * stop) {
  // iterate through all passengers- add to stop and erase from bus list
  std::list<Passenger *>::iterator it = passengers_.begin();
  for (; it != passengers_.end(); it++) {
    stop->AddPassengers((*it));
    passengers_.erase(it);
    // set iterator to beginning again, otherwise program segfaults
    it = passengers_.begin();
  }
}

void Bus::UnloadPassengers(Stop * stop) {
  // iterate through bus passengers
  std::list<Passenger *>::iterator it = passengers_.begin();
  int current_stop_id = stop->GetId();

  for (; it != passengers_.end(); it++) {
    // only offboard those with matching stop IDs
    if ((*it)->GetDestination() == current_stop_id) {
      stop->AddPassengers((*it));
      passengers_.erase(it);
      // set iterator to beginning again, otherwise program segfaults
      it = passengers_.begin();
    }
  }
}

bool Bus::Move() {
  UpdateBusData();
  distance_remaining_ -= speed_;
  // Arbitrary epsilon 0.00005 - for comparing floats
  // return true if at a stop, false if on transit
  return (distance_remaining_ <= 0.00005);
}

void Bus::Update() {
  bool is_at_stop = Move();

  // actions occur when bus is at stop. they cannot do actions during transit
  if (is_at_stop) {
    if (!IsTripComplete()) {
      UpdateBusData();
      // unload and load passengers between bus and stop
      Stop * current_stop = current_route_->GetDestinationStop();
      UnloadPassengers(current_stop);
      current_stop->LoadPassengers(this);
      // set next destination variables
      current_route_->NextStop();
      distance_remaining_ = current_route_->GetNextStopDistance();
    } else {
      // at end of route, offboard everyone
      Stop * current_stop = current_route_->GetDestinationStop();
      UnloadAllPassengers(current_stop);
    }

    if (current_route_->IsAtEnd() && current_route_ == outgoing_route_) {
      // at end of outgoing route, change route to incoming
      Stop * current_stop = current_route_->GetDestinationStop();
      UnloadAllPassengers(current_stop);
      UpdateBusData();
      ChangeRoute();
    }
  }
}

void Bus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;

  std::list<Passenger *>::iterator it;
  for (it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}

bool Bus::IsTripComplete() {
  return ((current_route_->IsAtEnd()
          && current_route_== incoming_route_)
          && distance_remaining_ <= 0.00005);
}

void Bus::ChangeRoute() {
  current_route_ = incoming_route_;
  distance_remaining_ = 0;
}

int Bus::GetCurrentStopId() const {
  return current_route_->GetDestinationStop()->GetId();
}

void Bus::UpdateBusData() {
  bus_data_.id = GetName();
  bus_data_.position = GetUpdateCoordinates();
  bus_data_.num_passengers = GetNumPassengers();
  bus_data_.capacity = GetCapacity();
}

BusData Bus::GetBusData() {
  return bus_data_;
}

std::string Bus::GetName() const {
  return name_;
}

Stop * Bus::GetNextStop() {
  return current_route_->GetDestinationStop();
}

size_t Bus::GetNumPassengers() {
  return (size_t)passengers_.size();
}

int Bus::GetCapacity() {
  return passenger_max_capacity_;
}

Position Bus::GetUpdateCoordinates() {
  Position curr_stop = current_route_->GetDestCoordinates();
  Position prev_stop = current_route_->GetPrevCoordinates();

  float avg_latitude;
  float avg_longitude;
  // if at a stop, return that stop's position
  if (distance_remaining_ <= 0.0000005) {
    avg_latitude = curr_stop.x;
    avg_longitude = curr_stop.y;
  } else {
    // if during transit, bus is at midpoint between stops
    avg_latitude = (curr_stop.x + prev_stop.x) / 2;
    avg_longitude = (curr_stop.y + prev_stop.y) / 2;
  }

  Position avg_stop;
  avg_stop.x = avg_latitude;
  avg_stop.y = avg_longitude;
  return avg_stop;
}
