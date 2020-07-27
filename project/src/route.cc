/**
 * @file route.cc
 *
 * @copyright Jack Dong, All rights reserved.
 */
#include "src/route.h"
#include <list>

Route::Route(std::string name, Stop ** stops, double * distances,
             int num_stops, PassengerGenerator * pass_gen) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }

  name_ = name;
  num_stops_ = num_stops;
  destination_stop_ = stops_.front();
  destination_stop_index_ = distances_between_.front();
  // generate passengers upon route creation
  generator_ = pass_gen;
  (*generator_).GeneratePassengers();
}

Route * Route::Clone() {
  std::string name_copy = name_;

  // cloning stops
  Stop ** stops_array = new Stop*[num_stops_];
  int k = 0;
  for (Stop* const&i : stops_) {
    stops_array[k++] = i;
  }
  // cloning double distances
  double * distance_array = new double[num_stops_-1];
  k = 0;
  for (double const&i : distances_between_) {
    distance_array[k++] = i;
  }

  Route * route_clone = new Route(name_copy, stops_array, distance_array,
                                                  num_stops_, generator_);
  return route_clone;
}


void Route::Update() {
  // generate passengers at each time interval
  (*generator_).GeneratePassengers();
  std::list<Stop *>::iterator it;
  for (it = stops_.begin(); it != stops_.end(); it++) {
    (*it)->Update();
  }
  UpdateRouteData();
}

void Route::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  int stop_counter = 0;
  std::list<Stop *>::const_iterator it;
  for (it = stops_.begin(); it != stops_.end(); it++) {
    (*it)->Report(std::cout);
    stop_counter++;
  }
}

bool Route::IsAtEnd() {
  return (destination_stop_ == stops_.back());
}

void Route::NextStop() {
  // Iterates to the current stop, then advance by one.
  std::list<Stop *>::iterator it = stops_.begin();
  for (; it != stops_.end(); it++) {
    if (destination_stop_ == (*it)) {
      destination_stop_ = *(std::next(it, 1));
      destination_stop_index_++;
      break;
    }
  }
}

Stop * Route::GetDestinationStop() const {
  return destination_stop_;
}

double Route::GetTotalRouteDistance() const {
  // iterate through while counting
  double total_distance = 0;

  std::list<double>::const_iterator it = distances_between_.begin();
  for (; it != distances_between_.end(); it++) {
      total_distance += (*it);
  }
  return total_distance;
}

double Route::GetNextStopDistance() const {
  std::list<double>::const_iterator it = distances_between_.begin();
  std::advance(it, destination_stop_index_-1);
  // use destination_stop_index_-1 because .begin() starts at the first already

  if ((*it) <= 0.00005) {
    // arbitrary epsilon, for comparing floats
    // there are cases when distance is 3.88e-300
    return 0;
  }
  return (*it);
}

Position Route::GetPrevCoordinates() {
  std::list<Stop *>::iterator it = stops_.begin();  // leading ptr
  std::list<Stop *>::iterator prev = it;  // trailing ptr

  for (; it != stops_.end(); it++) {
    // once leading ptr is equal to the current stop, return the previous ptr
    if ((*it) == destination_stop_) {
      return (*prev)->GetCoordinates();
    }
    prev = it;
  }
  // if current stop and it both are .begin() then return its coordinates
  return (*stops_.begin())->GetCoordinates();
}

Position Route::GetDestCoordinates() {
  return destination_stop_->GetCoordinates();
}

std::string Route::GetName() {
  return name_;
}

std::list<Stop *> Route::GetStops() {
  return stops_;
}

void Route::UpdateRouteData() {
  route_data_.id = GetName();
  route_data_.stops = GetStopStructVect();
}

RouteData Route::GetRouteData() {
  return route_data_;
}

std::vector<StopData> Route::GetStopStructVect() {
  std::vector<StopData> stop_structs;
  std::list<Stop *>::iterator it = stops_.begin();
  // creates vector of StopData from stop list
  for (; it != stops_.end(); it++) {
    StopData stop_struct;
    stop_struct = (*it)->GetStopData();
    stop_structs.push_back(stop_struct);
  }
  return stop_structs;
}

Position Route::GetLastStopPosition() {
  Stop * last_stop = stops_.back();
  return (last_stop->GetCoordinates());
}
