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

class BusTest : public ::testing::Test {
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

TEST_F(BusTest, ConstructorTest) {
	EXPECT_EQ(bus->GetName(), "Bus");
	EXPECT_EQ(bus->GetNumPassengers(), (size_t)0);
	EXPECT_EQ(bus->GetCapacity(), 60);
	EXPECT_EQ(bus->IsTripComplete(), false);
};


TEST_F(BusTest, LoadPassengerTest) {
	Bus * temp_bus = new Bus("Small",route_out, route_in, 1, 1);
	EXPECT_EQ(temp_bus->GetNumPassengers(), 0);

	EXPECT_EQ(temp_bus->LoadPassenger(p1), true);
	EXPECT_EQ(temp_bus->GetNumPassengers(), 1);

	EXPECT_NE(temp_bus->LoadPassenger(p2), true);
	EXPECT_EQ(temp_bus->LoadPassenger(p2), false);
	EXPECT_EQ(temp_bus->GetNumPassengers(), 1);
};

TEST_F(BusTest, UnloadPassengersTest) {
	bus->LoadPassenger(p1);
	bus->LoadPassenger(p2);
	bus->LoadPassenger(p3);
	bus->LoadPassenger(p4);
	bus->LoadPassenger(p5);
	EXPECT_EQ(bus->GetNumPassengers(), 5);

	bus->UnloadPassengers(stop_1);
	EXPECT_NE(bus->GetNumPassengers(), 5);
	EXPECT_EQ(bus->GetNumPassengers(), 4);
	bus->UnloadPassengers(stop_2);
	EXPECT_NE(bus->GetNumPassengers(), 4);
	EXPECT_EQ(bus->GetNumPassengers(), 3);
	bus->UnloadPassengers(stop_3);
	EXPECT_NE(bus->GetNumPassengers(), 3);
	EXPECT_EQ(bus->GetNumPassengers(), 2);
	bus->UnloadPassengers(stop_4);
	EXPECT_NE(bus->GetNumPassengers(), 2);
	EXPECT_EQ(bus->GetNumPassengers(), 1);
	bus->UnloadPassengers(stop_5);
	EXPECT_NE(bus->GetNumPassengers(), 1);
	EXPECT_EQ(bus->GetNumPassengers(), 0);
};

TEST_F(BusTest, MoveTest) {
	EXPECT_EQ(bus->GetCurrentStopId(), 4);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 5);
	bus->Update();
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 5);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 1);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 2);
};

TEST_F(BusTest, UpdateTest) {
	EXPECT_EQ(bus->GetCurrentStopId(), 4);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 5);
	bus->Update();
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 5);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 1);
	bus->Update();
	EXPECT_EQ(bus->GetCurrentStopId(), 2);
};

TEST_F(BusTest, ChangeRouteTest) {
	EXPECT_EQ(bus->GetCurrentStopId(), 4);
	bus->ChangeRoute();
	EXPECT_NE(bus->GetCurrentStopId(), 4);
	EXPECT_EQ(bus->GetCurrentStopId(), 1);

	Bus* temp_bus = new Bus("temp", route_out, route_in, 60, 1);
	temp_bus->Update();
	temp_bus->Update();
	temp_bus->Update();
	EXPECT_EQ(temp_bus->GetCurrentStopId(), 5);
	temp_bus->Update();
	EXPECT_EQ(temp_bus->GetCurrentStopId(), 1);
};

TEST_F(BusTest, GetCurrentStopIdTest) {
	EXPECT_EQ(bus->GetCurrentStopId(), 4);
	bus->ChangeRoute();
	EXPECT_EQ(bus->GetCurrentStopId(), 1);
};

TEST_F(BusTest, UpdateBusDataTest) {
	bus->UpdateBusData();
	BusData data = bus->GetBusData();
	Position pos = data.position;

	EXPECT_EQ(data.id, "Bus");
	EXPECT_EQ(data.num_passengers, 0);
	EXPECT_EQ(pos.x, 40);
	EXPECT_EQ(pos.y, 4);

	bus->Move();
	bus->Move();
	bus->Move();
	EXPECT_EQ(bus->LoadPassenger(p1), true);
	bus->UpdateBusData();
	data = bus->GetBusData();
	pos = data.position;

	EXPECT_EQ(data.id, "Bus");
	EXPECT_EQ(data.num_passengers, 1);
	EXPECT_EQ(pos.x, 40);
	EXPECT_EQ(pos.y, 4);
};

TEST_F(BusTest, GetBusDataTest) {
	bus->UpdateBusData();
	BusData data = bus->GetBusData();
	Position pos = data.position;

	EXPECT_EQ(data.id, "Bus");
	EXPECT_EQ(data.num_passengers, 0);
	EXPECT_EQ(pos.x, 40);
	EXPECT_EQ(pos.y, 4);

	bus->Move();
	bus->Move();
	bus->Move();
	bus->Move();
	EXPECT_EQ(bus->LoadPassenger(p1), true);
	bus->UpdateBusData();
	data = bus->GetBusData();
	pos = data.position;

	EXPECT_EQ(data.id, "Bus");
	EXPECT_EQ(data.num_passengers, 1);
	EXPECT_EQ(pos.x, 40);
	EXPECT_EQ(pos.y, 4);
};

TEST_F(BusTest, GetUpdateCoordinatesTest) {
	Position pos = bus->GetUpdateCoordinates();
	EXPECT_EQ(pos.x, 40);
	EXPECT_EQ(pos.y, 4);

	for (int i = 0; i < 4; i++) {
		bus->Update();
	}

	pos = bus->GetUpdateCoordinates();
	EXPECT_EQ(pos.x, 10);
	EXPECT_EQ(pos.y, 1);

	bus->Update();
	pos = bus->GetUpdateCoordinates();
	EXPECT_EQ(pos.x, 15);
	EXPECT_EQ(pos.y, 1.5);
};

TEST_F(BusTest, IsTripCompleteTest) {
	Bus * new_bus = new Bus("temp", route_out, route_in, 60, 1);
	for (int i = 0; i < 10; i++) {
		new_bus->Update();
	}
	EXPECT_EQ(new_bus->IsTripComplete(), true);

	Route * route_in1 = new Route("RouteIn", stops_in, dist_in, 3, gen_in);
	Route * route_out1 = new Route("RouteOut", stops_out, dist_out, 3, gen_out);
	Bus * bus1 = new Bus("bus1", route_out1, route_in1, 60, 1);
	for (int i = 0; i < 3; i++) {
		bus1->Update();
	}
	EXPECT_EQ(bus1->IsTripComplete(), false);
};
