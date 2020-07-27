/**
 * @file passenger.cc
 *
 * @copyright Jack Dong, All rights reserved.
 */

#include <iostream>
#include <string>

#include "src/passenger.h"

int Passenger::count_ = 0;

Passenger::Passenger(int destination_stop_id, std::string name) {
  name_ = name;
  destination_stop_id_ = destination_stop_id;
  wait_at_stop_ = 0;
  time_on_bus_ = 0;
  id_ = count_;
  // increase passenger unique ID and global count
  count_++;
}

void Passenger::Update() {
  // increment passengers' time on bus or at stop
  // depending on their location
  if (time_on_bus_ >= 1) {
    time_on_bus_++;
  } else {
    wait_at_stop_++;
  }
}

void Passenger::GetOnBus() {
  // change status of bus from 0 to 1 when onboarding
  if (time_on_bus_ <= 0) {
    time_on_bus_ = 1;
  }
}

int Passenger::GetTotalWait() const {
  // total time
  return wait_at_stop_ + time_on_bus_;
}

bool Passenger::IsOnBus() const {
  return (time_on_bus_ >= 1);
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

void Passenger::Report(std::ostream& out) const {
  out << "Name: " << name_ << std::endl;
  out << "Destination: " << destination_stop_id_ << std::endl;
  out << "Total Wait: " << GetTotalWait() << std::endl;
  out << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  out << "\tTime on bus: " << time_on_bus_ << std::endl;
}
