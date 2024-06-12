#include "s21_tests.h"

TEST(DetTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  double count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  double det = A.Determinant();
  EXPECT_NEAR(det, 0, 1e-6);
}

TEST(DetTest, test_2) {
  S21Matrix A = S21Matrix(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = 1;
    }
  }
  A(0, 1) = -1;
  A(1, 0) = 2;
  A(2, 2) = 2;
  double det = A.Determinant();
  EXPECT_NEAR(det, 5, 1e-6);
}

TEST(DetTest, test_3) {
  S21Matrix A = S21Matrix(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 4;
  A(1, 1) = 5;
  double det = A.Determinant();
  EXPECT_NEAR(det, -3, 1e-6);
}

TEST(DetTest, test_4) {
  S21Matrix A = S21Matrix(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      count++;
    }
  }
  EXPECT_THROW(A.Determinant(), MyExceptions::CalcComplements);
}

TEST(DetTest, test_5) {
  S21Matrix A = S21Matrix(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = count;
      count++;
    }
  }
  double det = A.Determinant();
  EXPECT_NEAR(det, 0, 1e-6);
}

TEST(DetTest, test_6) {
  S21Matrix A = S21Matrix(5, 5);
  double count = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A(0, 0) = 11;
  A(0, 1) = 21;
  A(1, 2) = -8;
  A(4, 4) = -25;
  double det = A.Determinant();
  EXPECT_NEAR(det, -148000, 1e-6);
}

TEST(DetTest, test_7) {
  S21Matrix A = S21Matrix(4, 4);
  double count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A(i, j) = count;
      count++;
    }
  }
  A(0, 0) = -5;
  A(2, 2) = -11;
  double det = A.Determinant();
  EXPECT_NEAR(det, -2112, 1e-6);
}
