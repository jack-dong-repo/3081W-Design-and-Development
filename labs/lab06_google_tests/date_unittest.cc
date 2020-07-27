#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <string>

#include "date.h"

//@TODO:
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	  first_day = Date(2018, 9, 4);
	  last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

//@TODO: datevoid
TEST_F(DateTest, DateVoidConstructorTests) {
   // defaults to current time, build string of expected output
   Date y2k;              // y2k
   Date ind_day;          // US Independence
   Date best_holiday;     // Halloween    std::time_t t = std::time(0);

   std::time_t t = std::time(0);
   std::tm* now = std::localtime(&t);
   int year = now -> tm_year + 1900;
   int month = now -> tm_mon + 1;
   int day = now -> tm_mday;
   std::string expected_out;

   // build expected_output string
   if (month < 10) {
       expected_out += "0";
   }
   expected_out += patch::to_string(month) + "-";
   if (day < 10) {
       expected_out += "0";
   }
   expected_out += patch::to_string(day) + "-";
   expected_out += patch::to_string(year);

   testing::internal::CaptureStdout();
   y2k.PrintUsDate(false);
   std::string output_1 = testing::internal::GetCapturedStdout();

   testing::internal::CaptureStdout();
   ind_day.PrintUsDate(false);
   std::string output_2 = testing::internal::GetCapturedStdout();

   testing::internal::CaptureStdout();
   best_holiday.PrintUsDate(false);
   std::string output_3 = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output_1, expected_out);
   EXPECT_EQ(output_2, expected_out);
   EXPECT_EQ(output_3, expected_out);
}

//@TODO: Dateyearmonthday
TEST_F(DateTest, DateYearMonthDay) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  EXPECT_EQ(y2k.GetUsDate(), "12-31-1999");
  EXPECT_EQ(ind_day.GetUsDate(), "07-04-1776");
  EXPECT_EQ(best_holiday.GetUsDate(), "10-31-2018");
}

//@TODO: Dateepoch
TEST_F(DateTest, DateEpochConstructorTests){

  Date y2k(1569865378);              // y2k
  Date ind_day(0);            // US Independence
  Date best_holiday(815160222);     // Halloween

  std::string expected_out_1 = "09-30-2019";
  std::string expected_out_2 = "01-01-1970";
  std::string expected_out_3 = "10-31-1995";


  //std::string expected_output =
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();


  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

//@TODO: operatorplusTests
TEST_F(DateTest, OperatorPlusTest) {
  Date y2k(1999, 12, 31);              // y2k

  std::string expected_out_1 = "2000-01-01\n";
  std::string expected_out_2 = "2000-12-30\n";
  std::string expected_out_3 = "1998-12-30\n";
  std::string expected_out_4 = "1999-12-31\n";

  testing::internal::CaptureStdout();
  y2k.operator+(1).PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator+(365).PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator+(-366).PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator+(0).PrintDate(true);
  std::string output4 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
}

// TODO: operaterminusTests
TEST_F(DateTest, OperatorMinusTest) {
  Date y2k(1999, 12, 31);              // y2k

  std::string expected_out_1 = "1999-12-01\n";
  std::string expected_out_2 = "1998-12-31\n";
  std::string expected_out_3 = "2000-12-30\n";
  std::string expected_out_4 = "1999-12-31\n";

  testing::internal::CaptureStdout();
  y2k.operator-(30).PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator-(365).PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator-(-365).PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  y2k.operator-(0).PrintDate(true);
  std::string output4 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
}

// Get Date with new Line
TEST_F(DateTest, GetDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  EXPECT_EQ(y2k.GetDate(), "1999-12-31");
  EXPECT_EQ(ind_day.GetDate(), "1776-07-04");
  EXPECT_EQ(best_holiday.GetDate(), "2018-10-31");
}

// Get Us Date with new Line
TEST_F(DateTest, GetUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  EXPECT_EQ(y2k.GetUsDate(), "12-31-1999");
  EXPECT_EQ(ind_day.GetUsDate(), "07-04-1776");
  EXPECT_EQ(best_holiday.GetUsDate(), "10-31-2018");
}

// Print Date with new line
TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

// Print Date without new line
TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

// Print Us Date with new line
TEST_F(DateTest, PrintUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

// Print Us Date without new line
TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, DaysBetweenLeapYearTests) {
  Date date1(2016, 1, 1);
  Date date2(2016, 3, 1);

  std::string expected_out_1 = "01-01-2016";
  std::string expected_out_2 = "03-01-2016";

  EXPECT_EQ(date1.GetUsDate(), expected_out_1);
  EXPECT_EQ(date2.GetUsDate(), expected_out_2);
  EXPECT_EQ(date1.DaysBetween(date2), 60) << "Days between is not calculated properly";
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

  Date fday(2016,1,1);
  Date lday(2016,3,1);

  std::string expected_out_1 = "01-01-2016";
  std::string expected_out_2 = "03-01-2016";

  testing::internal::CaptureStdout();
  fday.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  lday.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();


  EXPECT_EQ(output1, expected_out_1); // << "First day of class not setup properly";
  EXPECT_EQ(output2, expected_out_2); // << "Last day of class not setup properly";
  EXPECT_EQ(fday.DaysBetween(lday), 60); // << "Days between is not calculated properly";
}
/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
