/**
 * @file stop.cc
 *
 * @copyright Jack Dong, All rights reserved.
 */
#include <iostream>
#include <vector>

#include "./stop.h"
#include "./passenger.h"

Stop::Stop(int id, double longitude, double latitude) :
    id_(id), longitude_(longitude), latitude_(latitude) {
    // Defaults to Westbound Coffman Union stop
    // no initialization of list of passengers necessary
}

int Stop::AddPassengers(Passenger * pass) {
  passengers_.push_back(pass);
  return 1;
}

int Stop::LoadPassengers(Bus * bus) {
  int num_loaded_to_bus = 0;  // count passengers onboarded
  unsigned int size = passengers_.size();
  // each passenger will onboard the buss
  for (unsigned int i = 0; i < size; i++) {
    Passenger * off_passenger = passengers_.front();
    // checks if bus is at capacity
    if (bus->LoadPassenger(off_passenger)) {
      passengers_.pop_front();
      num_loaded_to_bus++;
    }
  }
  return num_loaded_to_bus;
}

void Stop::Update() {
  std::list<Passenger *>::iterator it;
  for (it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

int Stop::GetId() {
  return id_;
}

void Stop::Report(std::ostream& out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " << passengers_.size() << std::endl;
  std::list<Passenger *>::const_iterator it;
  for (it = passengers_.begin(); it != passengers_.end(); it++) {
    (*it)->Report(std::cout);
  }
}

Position Stop::GetCoordinates() {
  Position pos;
  pos.y = latitude_;
  pos.x = longitude_;
  return pos;
}

StopData Stop::GetStopData() {
  StopData stop_data_;
  stop_data_.id = std::to_string(GetId());
  stop_data_.position = GetCoordinates();
  stop_data_.num_people = passengers_.size();
  return stop_data_;
}

int Stop::GetPassengerCount() {
  return passengers_.size();
}
