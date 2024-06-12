#include "s21_tests.h"

TEST(S21InverseMatrixTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(A.InverseMatrix(), MyExceptions::DivisionZero);
}

TEST(S21InverseMatrixTest, test_2) {
  S21Matrix A = S21Matrix(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(A.InverseMatrix(), MyExceptions::CalcComplements);
}

TEST(S21InverseMatrixTest, test_3) {
  S21Matrix A = S21Matrix(1, 1);
  A(0, 0) = 2;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 1);
  EXPECT_EQ(R.GetCols(), 1);
  EXPECT_NEAR(R(0, 0), 0.5, 1e-6);
}

TEST(S21InverseMatrixTest, test_4) {
  S21Matrix A = S21Matrix(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 2);
  EXPECT_EQ(R.GetCols(), 2);
  EXPECT_NEAR(R(0, 0), -2, 1e-6);
  EXPECT_NEAR(R(0, 1), 1, 1e-6);
  EXPECT_NEAR(R(1, 0), 1.5, 1e-6);
  EXPECT_NEAR(R(1, 1), -0.5, 1e-6);
}

TEST(S21InverseMatrixTest, test_5) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A(0, 0) = 2;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  EXPECT_NEAR(R(0, 0), 1, 1e-6);
  EXPECT_NEAR(R(0, 1), -2, 1e-6);
  EXPECT_NEAR(R(0, 2), 1, 1e-6);
  EXPECT_NEAR(R(1, 0), -2, 1e-6);
  EXPECT_NEAR(R(1, 1), 1, 1e-6);
  EXPECT_NEAR(R(1, 2), 0, 1e-6);
  EXPECT_NEAR(R(2, 0), 1, 1e-6);
  EXPECT_NEAR(R(2, 1), (2.0 / 3.0), 1e-6);
  EXPECT_NEAR(R(2, 2), (-2.0 / 3.0), 1e-6);
}

TEST(S21InverseMatrixTest, test_6) {
  S21Matrix A = S21Matrix(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A(0, 0) = 2;
  A(3, 3) = 2;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 4);
  EXPECT_EQ(R.GetCols(), 4);
  EXPECT_NEAR(R(0, 0), 1, 1e-6);
  EXPECT_NEAR(R(0, 1), -2, 1e-6);
  EXPECT_NEAR(R(0, 2), 1, 1e-6);
  EXPECT_NEAR(R(0, 3), 0, 1e-6);
  EXPECT_NEAR(R(1, 0), -2, 1e-6);
  EXPECT_NEAR(R(1, 1), (33.0 / 28.0), 1e-6);
  EXPECT_NEAR(R(1, 2), (-3.0 / 28.0), 1e-6);
  EXPECT_NEAR(R(1, 3), (-1.0 / 14.0), 1e-6);
  EXPECT_NEAR(R(2, 0), 1, 1e-6);
  EXPECT_NEAR(R(2, 1), (9.0 / 14.0), 1e-6);
  EXPECT_NEAR(R(2, 2), (-11.0 / 14.0), 1e-6);
  EXPECT_NEAR(R(2, 3), (1.0 / 7.0), 1e-6);
  EXPECT_NEAR(R(3, 0), 0, 1e-6);
  EXPECT_NEAR(R(3, 1), (-1.0 / 14.0), 1e-6);
  EXPECT_NEAR(R(3, 2), (1.0 / 7.0), 1e-6);
  EXPECT_NEAR(R(3, 3), (-1.0 / 14.0), 1e-6);
}

TEST(S21InverseMatrixTest, test_7) {
  S21Matrix A = S21Matrix(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  EXPECT_NEAR(R(0, 0), 1, 1e-6);
  EXPECT_NEAR(R(0, 1), -1, 1e-6);
  EXPECT_NEAR(R(0, 2), 1, 1e-6);
  EXPECT_NEAR(R(1, 0), -38, 1e-6);
  EXPECT_NEAR(R(1, 1), 41, 1e-6);
  EXPECT_NEAR(R(1, 2), -34, 1e-6);
  EXPECT_NEAR(R(2, 0), 27, 1e-6);
  EXPECT_NEAR(R(2, 1), -29, 1e-6);
  EXPECT_NEAR(R(2, 2), 24, 1e-6);
}

TEST(S21InverseMatrixTest, test_8) {
  S21Matrix A = S21Matrix(3, 3);
  A(0, 0) = 0;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  S21Matrix R = A.InverseMatrix();
  EXPECT_EQ(R.GetRows(), 3);
  EXPECT_EQ(R.GetCols(), 3);
  EXPECT_NEAR(R(0, 0), -1, 1e-6);
  EXPECT_NEAR(R(0, 1), 1, 1e-6);
  EXPECT_NEAR(R(0, 2), -1, 1e-6);
  EXPECT_NEAR(R(1, 0), 38, 1e-6);
  EXPECT_NEAR(R(1, 1), -35, 1e-6);
  EXPECT_NEAR(R(1, 2), 42, 1e-6);
  EXPECT_NEAR(R(2, 0), -27, 1e-6);
  EXPECT_NEAR(R(2, 1), 25, 1e-6);
  EXPECT_NEAR(R(2, 2), -30, 1e-6);
}
