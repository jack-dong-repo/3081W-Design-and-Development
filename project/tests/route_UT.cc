/* STUDENTS: YOU MUST ADD YOUR PASSENGER UNIT TESTS TO THIS FILE. FORMAT YOUR
 * TESTS TO FIT THE SPECIFICATIONS GIVEN BY THE TESTS PROVIDED IN THIS FILE.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"
#include "../src/bus.h"
#include "../src/random_passenger_generator.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class RouteTests : public ::testing::Test {
	protected:
		Passenger* p1;
		Passenger* p2;
		Passenger* p3;
		Passenger* p4;
		Passenger* p5;
		Passenger* p6;

		Stop* stop_0;
		Stop* stop_1;
		Stop* stop_2;
		Stop* stop_3;
		Stop* stop_4;
		Stop* stop_5;
		Stop* stop_6;

		Stop** stops_in;
		Stop** stops_out;
		std::list<Stop *> stops_in_list;
		std::list<Stop *> stops_out_list;

		double * dist_in;
		double * dist_out;

		Route* route_in;
		Route* route_out;

		RandomPassengerGenerator * gen_in;
		RandomPassengerGenerator * gen_out;

		Bus * bus;

	virtual void SetUp() {
		// passengers
		p1 = new Passenger(1,"Abby");
		p2 = new Passenger(2,"Bob");
		p3 = new Passenger(3,"Carly");
		p4 = new Passenger(4,"David");
		p5 = new Passenger(5,"Elle");
		p6 = new Passenger(6,"Franky");

		// stops with/out passengers
		stop_0 = new Stop(0);
		stop_1 = new Stop(1, 10, 1);
		stop_1->AddPassengers(p1);
		stop_1->AddPassengers(p2);
		stop_1->AddPassengers(p3);
		stop_2 = new Stop(2, 20, 2);
		stop_3 = new Stop(3, 30, 3);
		stop_3->AddPassengers(p1);
		stop_3->AddPassengers(p2);
		stop_4 = new Stop(4, 40, 4);
		stop_5 = new Stop(5, 50, 5);
		stop_6 = new Stop(6, 60, 6);

		stops_in = new Stop*[3];
		stops_in[0] = stop_1;
		stops_in[1] = stop_2;
		stops_in[2] = stop_3;
		stops_in_list.push_back(stop_1);
		stops_in_list.push_back(stop_2);
		stops_in_list.push_back(stop_3);


		stops_out = new Stop*[3];
		stops_out[0] = stop_4;
		stops_out[1] = stop_5;
		stops_out[2] = stop_6;
		stops_out_list.push_back(stop_4);
		stops_out_list.push_back(stop_5);
		stops_out_list.push_back(stop_6);

		// distances
		dist_in = new double[2];
		dist_out = new double[2];

		dist_in[0] = 1;
		dist_in[1] = 2;

		dist_out[0] = 3;
		dist_out[1] = 4;

		// probs
		std::list<double> probs_in;
		std::list<double> probs_out;

		probs_in.push_back(.15);
		probs_in.push_back(.30);
		probs_in.push_back(.20);
		probs_out.push_back(.05);
		probs_out.push_back(.10);
		probs_out.push_back(.15);

		// generatation
		gen_in = new RandomPassengerGenerator(probs_in, stops_in_list);
		gen_out = new RandomPassengerGenerator(probs_out, stops_out_list);

		// routes
		route_in = new Route("RouteIn", stops_in, dist_in, 3, gen_in);
		route_out = new Route("RouteOut", stops_out, dist_out, 3, gen_out);

		bus = new Bus("Bus", route_out, route_in, 60, 1);
	}

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RouteTests, ConstructorTest) {
	EXPECT_EQ(route_in->GetName(),"RouteIn");
	EXPECT_NE(route_in->GetName(),"RouteOut");
	EXPECT_EQ(route_in->GetDestinationStop()->GetId(),1);
	EXPECT_NE(route_in->GetDestinationStop()->GetId(),4);

	EXPECT_EQ(route_out->GetName(),"RouteOut");
	EXPECT_NE(route_out->GetName(),"RouteIn");
	EXPECT_EQ(route_out->GetDestinationStop()->GetId(),4);
	EXPECT_NE(route_out->GetDestinationStop()->GetId(),1);
};

TEST_F(RouteTests, CloneTest) {
	Route * route_temp = route_in->Clone();
	EXPECT_EQ(route_in->GetName(),"RouteIn");
	EXPECT_EQ(route_in->GetDestinationStop()->GetId(),1);

	EXPECT_EQ(route_temp->GetName(),"RouteIn");
	EXPECT_EQ(route_temp->GetDestinationStop()->GetId(),1);
};

TEST_F(RouteTests, IsAtEndTest) {
	EXPECT_EQ(route_in->IsAtEnd(),false);
	route_in->NextStop();
	EXPECT_EQ(route_in->IsAtEnd(),false);
	EXPECT_NE(route_in->IsAtEnd(),true);
	route_in->NextStop();
	EXPECT_EQ(route_in->IsAtEnd(),true);
};

TEST_F(RouteTests, NextStopTest) {
	EXPECT_EQ(route_in->IsAtEnd(),false);
	route_in->NextStop();
	EXPECT_EQ(route_in->IsAtEnd(),false);
	EXPECT_NE(route_in->IsAtEnd(),true);
	route_in->NextStop();
	EXPECT_EQ(route_in->IsAtEnd(),true);
};

TEST_F(RouteTests, GetDestinationStopTest) {
	EXPECT_EQ(route_in->GetDestinationStop()->GetId(), 1);
	route_in->NextStop();
	EXPECT_EQ(route_in->GetDestinationStop()->GetId(), 2);
	route_in->NextStop();
	EXPECT_EQ(route_in->GetDestinationStop()->GetId(), 3);
};

TEST_F(RouteTests, GetTotalRouteDistanceTest) {
	EXPECT_EQ(route_in->GetTotalRouteDistance(), 3);
	EXPECT_EQ(route_out->GetTotalRouteDistance(), 7);

	EXPECT_NE(route_out->GetTotalRouteDistance(), 2);
	EXPECT_NE(route_out->GetTotalRouteDistance(), 6);
};

TEST_F(RouteTests, GetNextStopDistanceTest) {
	EXPECT_EQ(route_in->GetNextStopDistance(), 1);
	route_in->NextStop();
	EXPECT_EQ(route_in->GetNextStopDistance(), 2);

	EXPECT_EQ(route_out->GetNextStopDistance(), 0);
	route_out->NextStop();
	EXPECT_EQ(route_out->GetNextStopDistance(), 3);
};

TEST_F(RouteTests, GetPrevCoordinatesTest) {
	Position prev = route_in->GetPrevCoordinates();
	EXPECT_EQ(prev.x, 10);
	EXPECT_EQ(prev.y, 1);

	route_in->NextStop();
	prev = route_in->GetPrevCoordinates();
	EXPECT_EQ(prev.x, 10);
	EXPECT_EQ(prev.y, 1);

	route_in->NextStop();
	prev = route_in->GetPrevCoordinates();
	EXPECT_EQ(prev.x, 20);
	EXPECT_EQ(prev.y, 2);
};

TEST_F(RouteTests, GetCurrCoordinatesTest) {
	Position prev = route_in->GetCurrCoordinates();
	EXPECT_EQ(prev.x, 10);
	EXPECT_EQ(prev.y, 1);

	route_in->NextStop();
	prev = route_in->GetCurrCoordinates();
	EXPECT_EQ(prev.x, 20);
	EXPECT_EQ(prev.y, 2);

	route_in->NextStop();
	prev = route_in->GetCurrCoordinates();
	EXPECT_EQ(prev.x, 30);
	EXPECT_EQ(prev.y, 3);
};

TEST_F(RouteTests, GetRouteDataTest) {
	route_in->UpdateRouteData();
	RouteData data = route_in->GetRouteData();
	EXPECT_EQ(data.id, "RouteIn");
	std::vector<StopData> route_stops = data.stops;

	std::vector<StopData> vector;
	vector.push_back(stop_1->GetStopData());
	vector.push_back(stop_2->GetStopData());
	vector.push_back(stop_3->GetStopData());

	for (int i = 0; i < 3; i++) {
		StopData r_stop = route_stops.at(i);
		StopData test_stop = vector.at(i);
		Position r_pos = r_stop.position;
		Position test_pos = test_stop.position;

		EXPECT_EQ(r_stop.id, test_stop.id);
		EXPECT_EQ(r_pos.x, test_pos.x);
		EXPECT_EQ(r_pos.y, test_pos.y);
		EXPECT_EQ(r_stop.num_people, test_stop.num_people);
	}
};

TEST_F(RouteTests, GetStopStructVectTest) {
	route_in->UpdateRouteData();
	std::vector<StopData> route_stops = route_in->GetStopStructVect();

	std::vector<StopData> vector;
	vector.push_back(stop_1->GetStopData());
	vector.push_back(stop_2->GetStopData());
	vector.push_back(stop_3->GetStopData());

	for (int i = 0; i < 3; i++) {
		StopData r_stop = route_stops.at(i);
		StopData test_stop = vector.at(i);
		Position r_pos = r_stop.position;
		Position test_pos = test_stop.position;

		EXPECT_EQ(r_stop.id, test_stop.id);
		EXPECT_EQ(r_pos.x, test_pos.x);
		EXPECT_EQ(r_pos.y, test_pos.y);
		EXPECT_EQ(r_stop.num_people, test_stop.num_people);
	}
};

TEST_F(RouteTests, GetLastStopPositionTest) {
	Position pos_in = route_in->GetLastStopPosition();
	EXPECT_EQ(pos_in.x, 30);
	EXPECT_EQ(pos_in.y, 3);

	Position pos_out = route_out->GetLastStopPosition();
	EXPECT_EQ(pos_out.x, 60);
	EXPECT_EQ(pos_out.y, 6);
};
