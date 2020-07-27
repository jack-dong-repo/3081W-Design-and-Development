/**
 * @file stop.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <vector>
#include <list>

#include "stop.h"

// Defaults to Westbound Coffman Union stop
Stop::Stop(int id, double longitude, double latitude) {
    // no initialization of list of passengers necessary
    id_ = id;
    longitude_ = longitude;
    latitude_ = latitude;
}

void Stop::LoadPassengers(Bus * bus) {
    // loading some passengers onto a bus
    std::list<Passenger*>::iterator i;
    for (auto i = passengers_.begin(); i != passengers_.end(); ++i) {
      (*i)->GetOnBus();
      bus->LoadPassenger((*i));
    }
}

void Stop::AddPassengers(Passenger * pass) {
    // add the passenger to the stop
    passengers_.push_back(pass);
}

int Stop::GetId() const {
    return id_;
}

void Stop::Report() const {
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Passengers waiting: " << passengers_.size() << std::endl;
    std::list<Passenger *>::const_iterator it;
    for (it = passengers_.begin(); it != passengers_.end(); it++) {
      (*it)->Report();
    }
}
