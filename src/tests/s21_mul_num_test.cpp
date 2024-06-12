#include "s21_tests.h"

TEST(MulNumberTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  S21Matrix R = A * 2;
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_NEAR(R(i, j), count * 2, 1e-6);
      count++;
    }
  }
}

TEST(MulNumberTest, test_2) {
  S21Matrix A = S21Matrix(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A *= 2;
  EXPECT_EQ(A.GetRows(), 4);
  EXPECT_EQ(A.GetCols(), 4);
  count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_NEAR(A(i, j), count * 2, 1e-6);
      count++;
    }
  }
}

TEST(MulNumberTest, test_3) {
  S21Matrix A = S21Matrix(4, 2);

  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A.MulNumber(2);

  EXPECT_EQ(A.GetRows(), 4);
  EXPECT_EQ(A.GetCols(), 2);
  count = 1;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_NEAR(A(i, j), count * 2, 1e-6);
      count++;
    }
  }
}