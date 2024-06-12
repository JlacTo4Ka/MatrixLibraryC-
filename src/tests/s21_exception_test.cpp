#include "s21_tests.h"

TEST(MyExceptionsTest, test_1) {
  MyExceptions::OperatorBrackets ex;
  const char* expected = "Operator '()' error: incorrect size\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_2) {
  MyExceptions::CalcComplements ex;
  const char* expected = "Calc complements error: size\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_3) {
  MyExceptions::Constructor ex;
  const char* expected =
      "Constructor error: count of rows and/or cols have to be greater zero\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_4) {
  MyExceptions::NullPtr ex;
  const char* expected = "The pointer to null: Incorrect memory allocation\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_5) {
  MyExceptions::DivisionZero ex;
  const char* expected = "Division by zero\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_6) {
  MyExceptions::MultSize ex;
  const char* expected =
      "MultSize error: Incorrect input, number of cols of first matrice should "
      "has the same number of rows second\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}

TEST(MyExceptionsTest, test_7) {
  MyExceptions::OutOfRange ex;
  const char* expected =
      "Sum or sub error: Incorrect input, matrices should have the same size\n";
  const char* result = ex.what();

  EXPECT_STREQ(expected, result);
}