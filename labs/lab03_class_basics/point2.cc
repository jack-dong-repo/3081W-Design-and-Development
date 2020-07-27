#include <iostream>
#include <cmath>
#include "point2.h"

using namespace std;

int Quadrant();
float DistanceBetween(Point2 other);
void Print();

Point2::Point2(float x, float y) {
	x_cord = x;
	y_cord = y;
}

int Point2::Quadrant() {
	if (x_cord > 0.0 && y_cord >= 0.0) {
		return 1;
	}
	else if (x_cord <= 0.0 && y_cord > 0.0) {
		return 2;
	}
	else if (x_cord < 0.0 && y_cord <= 0.0) {
		return 3;
	}
	else if (x_cord >= 0.0 && y_cord < 0.0) {
		return 4;
	}
	else return 0;
}

float Point2::DistanceBetween(Point2 other) {
	float x_dist = pow((other.x_cord-x_cord),2);
	float y_dist = pow((other.y_cord-y_cord),2);
	return sqrt(x_dist+y_dist);
}

void Point2::Print() {
	cout<<"("<<x_cord<<","<<y_cord<<")";
}