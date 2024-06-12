#include "s21_tests.h"

TEST(TransposeTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  S21Matrix R = A.Transpose();
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_NEAR(R(j, i), count, 1e-6);
      count++;
    }
  }
}

TEST(TransposeTest, test_2) {
  S21Matrix A = S21Matrix(3, 2);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A(i, j) = count;
      count++;
    }
  }

  S21Matrix R = A.Transpose();

  EXPECT_EQ(R.GetRows(), 2);
  EXPECT_EQ(R.GetCols(), 3);
  count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_EQ(R(j, i), count);
      count++;
    }
  }
}