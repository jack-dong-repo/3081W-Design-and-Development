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

class StopTests : public ::testing::Test {
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

	virtual void TearDown() {
		delete p1;
		delete p2;
		delete p3;
		delete p4;
		delete p5;
		delete p6;

		delete stop_0;
		delete stop_1;
		delete stop_2;
		delete stop_3;
		delete stop_4;
		delete stop_5;
		delete stop_6;
	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(StopTests, ConstructorTest) {
	EXPECT_EQ(stop_1->GetId(),1);
	Position location = stop_1->GetCoordinates();
	EXPECT_EQ(location.x, 10);
	EXPECT_EQ(location.y, 1);
};

TEST_F(StopTests, AddPassengerTest) {
	EXPECT_EQ(stop_0->GetPassengerCount(),0);
	EXPECT_EQ(stop_0->AddPassengers(p1),1);
	EXPECT_EQ(stop_0->GetPassengerCount(),1);
	EXPECT_EQ(stop_0->AddPassengers(p2),1);
	EXPECT_EQ(stop_0->GetPassengerCount(),2);
};

TEST_F(StopTests, LoadPassengersTest) {
	stop_0->AddPassengers(p1);
	stop_0->AddPassengers(p2);
	stop_0->AddPassengers(p3);

	EXPECT_EQ(stop_0->LoadPassengers(bus),3);
};

TEST_F(StopTests, GetCoordintesTest) {
	EXPECT_EQ(stop_1->GetId(),1);
	Position location = stop_1->GetCoordinates();
	EXPECT_EQ(location.x, 10);
	EXPECT_EQ(location.y, 1);
};

TEST_F(StopTests, GetStopDataTest) {
	Stop * stop_temp = new Stop(1,100,102);
	StopData data = stop_temp->GetStopData();
	Position pos = data.position;
	EXPECT_EQ(data.id, "1");
	EXPECT_EQ(pos.x, 100);
	EXPECT_EQ(pos.y, 102);
	EXPECT_EQ(data.num_people, 0);

	stop_temp->AddPassengers(p1);
	StopData data1 = stop_temp->GetStopData();
	EXPECT_EQ(data1.num_people, 1);
};

TEST_F(StopTests, GetPassengerCountTest) {
	EXPECT_EQ(stop_0->GetPassengerCount(), 0);
	stop_0->AddPassengers(p1);
	EXPECT_EQ(stop_0->GetPassengerCount(), 1);
};
