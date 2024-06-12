#include "s21_tests.h"

TEST(SubMatrix, test_1) {
  S21Matrix A;
  S21Matrix B;

  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetCols(); j++) {
      B.SetIJ(i, j, -1);
    }
  }

  A.SubMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(1, A(i, j));
    }
  }
};

TEST(SubMatrix, test_2) {
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

  matrix1.SubMatrix(matrix2);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    int count = 0;
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(count * 3, matrix1(i, j));
      count++;
    }
  }
};

TEST(SubMatrix, test_3) {
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

  matrix1.SubMatrix(matrix2);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    int count = 0;
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(count * 3, matrix1(i, j));
      count++;
    }
  }
};

TEST(SubMatrix, test_4) {
  S21Matrix A(2, 3);
  S21Matrix B(2, 3);
  double count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = count;
      B(i, j) = count;
      count++;
    }
  }
  A(0, 2) = 4;
  A = A - B;
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_NEAR(A(i, j), 0, 1e-6);
    }
  }
  EXPECT_NEAR(A(0, 2), 1, 1e-6);
  EXPECT_NEAR(A(1, 2), 0, 1e-6);
};

TEST(SubMatrix, test_5) {
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

  EXPECT_THROW(matrix1.SubMatrix(matrix2), MyExceptions::OutOfRange);
};

TEST(SubMatrix, test_6) {
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

  EXPECT_THROW(matrix1 - matrix2, MyExceptions::OutOfRange);
};

TEST(SubMatrix, test_7) {
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

  matrix1 -= matrix2;

  for (int i = 0; i < matrix1.GetRows(); i++) {
    int count = 0;
    for (int j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_EQ(count * 3, matrix1(i, j));
      count++;
    }
  }
};