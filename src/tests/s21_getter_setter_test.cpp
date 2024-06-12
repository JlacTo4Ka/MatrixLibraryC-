#include "s21_tests.h"

TEST(GetterSetterTest, test_1) {
  S21Matrix matrix;

  EXPECT_EQ(3, matrix.GetRows());
  EXPECT_EQ(3, matrix.GetCols());

  matrix.SetRows(3);
  matrix.SetCols(3);

  EXPECT_EQ(3, matrix.GetRows());
  EXPECT_EQ(3, matrix.GetCols());
}

TEST(GetterSetterTest, test_2) {
  S21Matrix matrix(2, 4);

  EXPECT_EQ(2, matrix.GetRows());
  EXPECT_EQ(4, matrix.GetCols());

  double count = 1;
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = count;
      count++;
    }
  }

  matrix.SetRows(3);
  matrix.SetCols(5);

  count = 1;
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      if (j == matrix.GetCols() - 1 || i == matrix.GetRows() - 1) {
        EXPECT_EQ(0, matrix(i, j));
      } else {
        EXPECT_EQ(count, matrix(i, j));
        count++;
      }
    }
  }
}

TEST(GetterSetterTest, test_3) {
  S21Matrix matrix(3, 4);

  EXPECT_EQ(3, matrix.GetRows());
  EXPECT_EQ(4, matrix.GetCols());

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = j + 1;
    }
  }

  matrix.SetRows(2);
  matrix.SetCols(3);

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_EQ(j + 1, matrix(i, j));
    }
  }
}
