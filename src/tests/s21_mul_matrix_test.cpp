#include "s21_tests.h"

TEST(MulMatrix, test_1) {
  S21Matrix A;
  S21Matrix B;

  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetCols(); j++) {
      B.SetIJ(i, j, -1);
    }
  }

  A.MulMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(0, A(i, j));
    }
  }
};

TEST(MulMatrix, test_2) {
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

  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(1, matrix1(0, 0));
  EXPECT_EQ(-1, matrix1(0, 1));
  EXPECT_EQ(2, matrix1(1, 0));
  EXPECT_EQ(-4, matrix1(1, 1));
};

TEST(MulMatrix, test_3) {
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

  EXPECT_THROW(matrix1.MulMatrix(matrix2), MyExceptions::MultSize);
};

TEST(MulMatrix, test_4) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(2, 1);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i + j + j);
    }
  }

  matrix1 = matrix1 * matrix2;

  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetCols(), 1);

  int count = 0;
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      count++;
      EXPECT_EQ(count, matrix1(i, j));
    }
  }
};

TEST(MulMatrix, test_5) {
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

  EXPECT_THROW(matrix1.MulMatrix(matrix2), MyExceptions::MultSize);
};

TEST(MulMatrix, test_6) {
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

  EXPECT_THROW(matrix1 * matrix2, MyExceptions::MultSize);
};

TEST(MulMatrix, test_7) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(2, 1);

  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      matrix1.SetIJ(i, j, i + j);
    }
  }

  for (int i = 0; i < matrix2.GetRows(); i++) {
    for (int j = 0; j < matrix2.GetCols(); j++) {
      matrix2.SetIJ(i, j, i + j + j);
    }
  }

  matrix1 *= matrix2;

  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetCols(), 1);

  int count = 0;
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      count++;
      EXPECT_EQ(count, matrix1(i, j));
    }
  }
};
