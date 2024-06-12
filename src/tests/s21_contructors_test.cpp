#include "s21_tests.h"

TEST(S21MatrixConstructor, test_1) {
  S21Matrix matrix1;

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(0, matrix1(i, j));
    }
  }
};

TEST(S21MatrixConstructor, test_2) {
  S21Matrix matrix1(2, 10);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(i + j, matrix1(i, j));
    }
  }
};

TEST(S21MatrixConstructor, test_3) {
  S21Matrix matrix1(2, 4);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j + i * i);
    }
  }
  S21Matrix matrix2 = S21Matrix(matrix1);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(i + j + i * i, matrix2(i, j));
    }
  }
};

TEST(S21MatrixConstructor, test_4) {
  S21Matrix matrix1;

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j + i * i);
    }
  }

  S21Matrix matrix2 = S21Matrix(std::move(matrix2));

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      EXPECT_EQ(i + j + i * i, matrix2(i, j));
    }
  }
};

TEST(S21MatrixConstructor, test_5) {
  EXPECT_THROW(S21Matrix matrix1(2, -1), MyExceptions::Constructor);
};
