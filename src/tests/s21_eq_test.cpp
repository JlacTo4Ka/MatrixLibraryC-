#include "s21_tests.h"

TEST(EqTest, test_1) {
  S21Matrix A = S21Matrix(3, 3);
  S21Matrix B = S21Matrix(3, 3);

  EXPECT_EQ((A == B), true);
}

TEST(EqTest, test_2) {
  S21Matrix A = S21Matrix(4, 3);
  S21Matrix B = S21Matrix(3, 3);

  EXPECT_EQ((A == B), false);
}

TEST(EqTest, test_3) {
  S21Matrix A = S21Matrix(3, 3);
  S21Matrix B = S21Matrix(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = 1;
      B(i, j) = 1;
    }
  }
  EXPECT_EQ((A == B), true);
}

TEST(EqTest, test_4) {
  S21Matrix A = S21Matrix(4, 3);
  S21Matrix B = S21Matrix(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = 1;
      B(i, j) = 1;
    }
  }

  EXPECT_EQ((A == B), false);
}

TEST(EqTest, test_5) {
  S21Matrix A = S21Matrix(3, 3);
  S21Matrix B = S21Matrix(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = 1;
      B(i, j) = 2;
    }
  }

  EXPECT_EQ((A == B), false);
}

TEST(EqTest, test_6) {
  S21Matrix A = S21Matrix(3, 3);
  S21Matrix B = S21Matrix(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = i;
      B(i, j) = i;
    }
  }
  EXPECT_EQ((A == B), true);
}

TEST(EqTest, test_7) {
  S21Matrix A = S21Matrix(3, 3);
  S21Matrix B = S21Matrix(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = i;
      B(i, j) = i + 1;
    }
  }
  EXPECT_EQ((A == B), false);
}