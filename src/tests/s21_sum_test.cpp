#include "s21_tests.h"

TEST(SumMatrix, test_1) {
  S21Matrix A;
  S21Matrix B;

  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetCols(); j++) {
      B.SetIJ(i, j, -1);
    }
  }

  A.SumMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(-1, A(i, j));
    }
  }
};

TEST(SumMatrix, test_2) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix2.SetIJ(i, j, i - j - j);
    }
  }

  matrix1.SumMatrix(matrix2);

  EXPECT_EQ(0, matrix1(0, 0));
  EXPECT_EQ(-1, matrix1(0, 1));
  EXPECT_EQ(2, matrix1(1, 0));
  EXPECT_EQ(1, matrix1(1, 1));
};

TEST(SumMatrix, test_3) {
  S21Matrix matrix1(2, 4);
  S21Matrix matrix2(2, 4);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i - j - j);
    }
  }

  matrix1.SumMatrix(matrix2);

  EXPECT_EQ(0, matrix1(0, 0));
  EXPECT_EQ(-1, matrix1(0, 1));
  EXPECT_EQ(-2, matrix1(0, 2));
  EXPECT_EQ(-3, matrix1(0, 3));
  EXPECT_EQ(2, matrix1(1, 0));
  EXPECT_EQ(1, matrix1(1, 1));
  EXPECT_EQ(0, matrix1(1, 2));
  EXPECT_EQ(-1, matrix1(1, 3));
};

TEST(SumMatrix, test_4) {
  S21Matrix A = S21Matrix(2, 3);
  S21Matrix B = S21Matrix(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      B(i, j) = count;
      count++;
    }
  }
  A(0, 2) = 4;
  S21Matrix R = A + B;
  EXPECT_EQ(R.GetRows(), 2);
  EXPECT_EQ(R.GetCols(), 3);
  EXPECT_NEAR(R(0, 0), 2, 1e-6);
  EXPECT_NEAR(R(0, 1), 4, 1e-6);
  EXPECT_NEAR(R(0, 2), 7, 1e-6);
  EXPECT_NEAR(R(1, 0), 8, 1e-6);
  EXPECT_NEAR(R(1, 1), 10, 1e-6);
  EXPECT_NEAR(R(1, 2), 12, 1e-6);
};

TEST(SumMatrix, test_5) {
  S21Matrix matrix1(2, 4);
  S21Matrix matrix2(1, 4);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i - j - j);
    }
  }

  EXPECT_THROW(matrix1.SumMatrix(matrix2), MyExceptions::OutOfRange);
};

TEST(SumMatrix, test_6) {
  S21Matrix matrix1(2, 4);
  S21Matrix matrix2(1, 4);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i - j - j);
    }
  }

  EXPECT_THROW(matrix1 + matrix2, MyExceptions::OutOfRange);
};

TEST(SumMatrix, test_7) {
  S21Matrix matrix1(2, 4);
  S21Matrix matrix2(2, 4);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i - j - j);
    }
  }

  matrix1 += matrix2;

  EXPECT_EQ(0, matrix1(0, 0));
  EXPECT_EQ(-1, matrix1(0, 1));
  EXPECT_EQ(-2, matrix1(0, 2));
  EXPECT_EQ(-3, matrix1(0, 3));
  EXPECT_EQ(2, matrix1(1, 0));
  EXPECT_EQ(1, matrix1(1, 1));
  EXPECT_EQ(0, matrix1(1, 2));
  EXPECT_EQ(-1, matrix1(1, 3));
};