/**
 * @file main.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

#include "Date.h"

#include <iostream>
#include <string>

using namespace std;

void doInterestingThing(int yr) {
  // variables used in this method
  int* array_len;
  Date d1;
  Date d2;
  Date d3;
  Date** birthday_list;

  cout << " ... A set of Dates ... " << endl;

  array_len = NULL;
  d2 = Date(yr, 4, 19);
  d3 = d2.copy();

  int len = 4;
  array_len = &len;

  cout << "default date is: " << d1.show() << endl;

  cout << "date d2 is: " << d2.show() << endl;

  cout << "date d3 is: " << d3.show() << endl;

  cout << " ... Now print out 4 dates in reverse time order ... " << endl;

  birthday_list = new Date*[*array_len];
  // accumulate the all dates January 1, from 1990 to 1990+array_len
  for (int i = 0; i < (*array_len); i++) {
    birthday_list[i] = new Date(1990+i, 1, 1);
  }

  // now show the dates accumulated in reverse order
  for (int i = (*array_len)-1; i >= 0; --i) {
    cout << "date is: " << birthday_list[i]->show() << endl;
  }

  // now set the dates to January 2
  for (int i = 0; i <= (*array_len)-1; i++) {
    *birthday_list[i] = Date(1990+i, 1, 2);
  }

  cout << "the first date is: " << birthday_list[0]->show() << endl;
}

int main() {
  doInterestingThing(1998);
  doInterestingThing(1999);
  cout << endl << "... Goodbye ..." << endl;
}
