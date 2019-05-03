#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


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

TEST_F(DateTest, SpecialDateConstructorTest) {
  Date epoch_test(10);
  Date void_constructor;

  std::time_t t = std::time(0);
  std::tm* today = std::localtime(&t);

  int year = today->tm_year + 1900;
  int month = today->tm_mon + 1;
  int day = today->tm_mday;

  Date correct(year, month, day);

  std::string expected_out_1 = "1970-01-01";
  std::string expected_out_2 = correct.GetDate();

  EXPECT_EQ(epoch_test.GetDate(), expected_out_1) << "Epoch Constructor failed";
  EXPECT_EQ(void_constructor.GetDate(), expected_out_2) << "Current Date Constructor failed";
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  Date day_in_spec_year(2020, 2, 1);
  Date another_spec_day(2020, 4, 1);
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(day_in_spec_year.DaysBetween(another_spec_day), 60) << "Days between is not calculated properly for special year";
}

TEST_F(DateTest, GetDateTests) {
  Date y2k(1999, 12, 31);
  Date ind_day(1776, 7, 4);
  Date best_holiday(2018, 10, 31);

  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "Days not print properly on first day";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Days not print properly on last day";
  EXPECT_EQ(y2k.GetDate(), "1999-12-31") << "Days not print properly on y2k";
  EXPECT_EQ(ind_day.GetDate(), "1776-07-04") << "Days not print properly on US Independence Day";
  EXPECT_EQ(best_holiday.GetDate(), "2018-10-31") << "Days not print properly on Holloween";
}

TEST_F(DateTest, GetUsDateTests) {
  Date y2k(1999, 12, 31);
  Date ind_day(1776, 7, 4);
  Date best_holiday(2018, 10, 31);

  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "Days not print properly on first day";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Days not print properly on last day";
  EXPECT_EQ(y2k.GetUsDate(), "12-31-1999") << "Days not print properly on y2k";
  EXPECT_EQ(ind_day.GetUsDate(), "07-04-1776") << "Days not print properly on US Independence Day";
  EXPECT_EQ(best_holiday.GetUsDate(), "10-31-2018") << "Days not print properly on Holloween";
}

TEST_F(DateTest, Operator_Minus) {
  Date month_begin(2018, 10, 01);
  Date new_date_1 = month_begin - 2;
  Date new_date_2 = new_date_1 - 1;

  EXPECT_EQ(new_date_1.GetDate(), "2018-09-29") << "Overwrite - operator works incorrect";
  EXPECT_EQ(new_date_2.GetDate(), "2018-09-28") << "Overwrite - operator works incorrect";
}

TEST_F(DateTest, Operator_Plus) {
  Date month_begin(2018, 9, 28);
  Date new_date_1 = month_begin + 2;
  Date new_date_2 = new_date_1 + 1;

  EXPECT_EQ(new_date_1.GetDate(), "2018-09-30") << "Overwrite + operator works incorrect";
  EXPECT_EQ(new_date_2.GetDate(), "2018-10-01") << "Overwrite + operator works incorrect";
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
