#include "s21_tests.h"

TEST(CalcComplementsTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  S21Matrix R = A.CalcComplements();
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  EXPECT_NEAR(R(0, 0), -3, 1e-6);
  EXPECT_NEAR(R(0, 1), 6, 1e-6);
  EXPECT_NEAR(R(0, 2), -3, 1e-6);
  EXPECT_NEAR(R(1, 0), 6, 1e-6);
  EXPECT_NEAR(R(1, 1), -12, 1e-6);
  EXPECT_NEAR(R(1, 2), 6, 1e-6);
  EXPECT_NEAR(R(2, 0), -3, 1e-6);
  EXPECT_NEAR(R(2, 1), 6, 1e-6);
  EXPECT_NEAR(R(2, 2), -3, 1e-6);
}

TEST(CalcComplementsTest, test_2) {
  S21Matrix A = S21Matrix(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(A.CalcComplements(), MyExceptions::CalcComplements);
}

TEST(CalcComplementsTest, test_3) {
  S21Matrix A = S21Matrix(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;
  A = A.CalcComplements();
  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 3);
  EXPECT_NEAR(A(0, 0), 0, 1e-6);
  EXPECT_NEAR(A(0, 1), 10, 1e-6);
  EXPECT_NEAR(A(0, 2), -20, 1e-6);
  EXPECT_NEAR(A(1, 0), 4, 1e-6);
  EXPECT_NEAR(A(1, 1), -14, 1e-6);
  EXPECT_NEAR(A(1, 2), 8, 1e-6);
  EXPECT_NEAR(A(2, 0), -8, 1e-6);
  EXPECT_NEAR(A(2, 1), -2, 1e-6);
  EXPECT_NEAR(A(2, 2), 4, 1e-6);
}

TEST(CalcComplementsTest, test_4) {
  S21Matrix A = S21Matrix(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A(2, 2) = 111;
  S21Matrix R = A.CalcComplements();
  EXPECT_EQ(R.GetRows(), 4);
  EXPECT_EQ(R.GetCols(), 4);
  EXPECT_NEAR(R(0, 0), -1600, 1e-6);
  EXPECT_NEAR(R(0, 1), 2400, 1e-6);
  EXPECT_NEAR(R(0, 2), 0, 1e-6);
  EXPECT_NEAR(R(0, 3), -800, 1e-6);
  EXPECT_NEAR(R(1, 0), 2400, 1e-6);
  EXPECT_NEAR(R(1, 1), -3600, 1e-6);
  EXPECT_NEAR(R(1, 2), 0, 1e-6);
  EXPECT_NEAR(R(1, 3), 1200, 1e-6);
  EXPECT_NEAR(R(2, 0), 0, 1e-6);
  EXPECT_NEAR(R(2, 1), 0, 1e-6);
  EXPECT_NEAR(R(2, 2), 0, 1e-6);
  EXPECT_NEAR(R(2, 3), 0, 1e-6);
  EXPECT_NEAR(R(3, 0), -800, 1e-6);
  EXPECT_NEAR(R(3, 1), 1200, 1e-6);
  EXPECT_NEAR(R(3, 2), 0, 1e-6);
  EXPECT_NEAR(R(3, 3), -400, 1e-6);
}