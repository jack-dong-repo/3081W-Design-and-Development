/**
 * @file passenger_generator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/passenger_generator.h"

#include "src/passenger.h"

PassengerGenerator::PassengerGenerator(std::list<double> probs,
                                       std::list<Stop *> stops) {
  int count = 0;
  int size = probs.size();
  std::list<double>::iterator it = probs.begin();

  // does not include last probability
  for (; count < size-1; count++) {
    generation_probabilities_.push_back((*it));
    std::advance(it, 1);
  }
  stops_ = stops;
}
