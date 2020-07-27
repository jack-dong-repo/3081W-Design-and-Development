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

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class PassengerTests : public ::testing::Test {

	protected:

  	Passenger* passenger;
		Passenger* p1;
		Passenger* p2;
		Passenger* p3;
		Passenger* p4;

	virtual void SetUp() {
    	passenger = new Passenger();
			p1 = new Passenger(1,"Abby");
			p2 = new Passenger(2,"Bob");
			p3 = new Passenger(3,"Carly");
			p4 = new Passenger(4,"David");
  	}

  	virtual void TearDown() {
    	delete passenger;
			delete p1;
			delete p2;
			delete p3;
			delete p4;
  	}
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PassengerTests, Constructor) {
	// Null constructor
  EXPECT_EQ(passenger->GetDestination(),-1);
	EXPECT_EQ(passenger->IsOnBus(),false);
	EXPECT_EQ(passenger->GetTotalWait(),0);

	passenger->Update();
	EXPECT_EQ(passenger->GetTotalWait(),1);

	passenger->Update();
	passenger->GetOnBus();
	EXPECT_EQ(passenger->IsOnBus(), true);
	EXPECT_EQ(passenger->GetTotalWait(), 3);

	// Parameterized constructor
	EXPECT_EQ(p1->GetDestination(),1);
	EXPECT_EQ(p1->IsOnBus(),false);
	EXPECT_EQ(p1->GetTotalWait(),0);

	p1->Update();
	EXPECT_EQ(p1->GetTotalWait(),1);

	p1->Update();
	p1->GetOnBus();
	EXPECT_EQ(p1->IsOnBus(), true);
	EXPECT_EQ(p1->GetTotalWait(), 3);
};


TEST_F(PassengerTests, UpdateTest) {
	EXPECT_EQ(p2->GetTotalWait(),0);
	p2->Update();
	EXPECT_NE(p2->GetTotalWait(),0);
	EXPECT_EQ(p2->GetTotalWait(),1);
	p2->GetOnBus();
	EXPECT_NE(p2->GetTotalWait(),1);
	EXPECT_EQ(p2->GetTotalWait(),2);
	p2->Update();
	EXPECT_NE(p2->GetTotalWait(),2);
	EXPECT_EQ(p2->GetTotalWait(),3);

};

TEST_F(PassengerTests, GetOnBusTest) {
	EXPECT_EQ(p3->GetTotalWait(),0);
	p3->GetOnBus();
	EXPECT_NE(p3->GetTotalWait(),0);
	EXPECT_EQ(p3->GetTotalWait(),1);

	p3->GetOnBus();
	EXPECT_NE(p3->GetTotalWait(),0);
	EXPECT_EQ(p3->GetTotalWait(),1);
};

TEST_F(PassengerTests, IsOnBusTest) {
	EXPECT_EQ(p2->IsOnBus(),false);
	p2->GetOnBus();
	EXPECT_NE(p2->IsOnBus(),false);
	EXPECT_EQ(p2->IsOnBus(),true);

	EXPECT_EQ(p4->IsOnBus(),false);
};

TEST_F(PassengerTests, GetDestinationTest) {
	EXPECT_EQ(passenger->GetDestination(),-1);
	EXPECT_EQ(p1->GetDestination(),1);
	EXPECT_EQ(p2->GetDestination(),2);
	EXPECT_EQ(p3->GetDestination(),3);
	EXPECT_EQ(p4->GetDestination(),4);
};
