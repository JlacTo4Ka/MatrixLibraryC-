#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) {
    throw MyExceptions::CalcComplements();
  }

  double res = 0;

  if (rows_ == 1) {
    res = matrix_[0][0];
  }

  if (rows_ == 2) {
    res = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  }

  if (rows_ > 2) {
    res = FindDeterminant();
  }

  return res;
}

double S21Matrix::FindDeterminant() {
  double res_determinant = 0;

  for (int j = 0; j < cols_; j++) {
    double temp_res = 0;

    temp_res = GetMinor(0, j);

    if ((0 + j) % 2 == 0) {
      res_determinant += matrix_[0][j] * temp_res;
    } else {
      res_determinant -= matrix_[0][j] * temp_res;
    }
  }

  return res_determinant;
}

double S21Matrix::GetMinor(int i, int j) {
  double res = 0;

  S21Matrix minor(rows_ - 1, cols_ - 1);

  FillMinor(i, j, minor);

  res = minor.Determinant();

  return res;
}

void S21Matrix::FillMinor(int i, int j, S21Matrix& minor) {
  int row_shift = 0;
  int col_shift = 0;

  for (int n = 0; n < minor.rows_; n++) {
    if (n == i) {
      row_shift = 1;
    }

    for (int m = 0; m < minor.cols_; m++) {
      if (m == j) {
        col_shift = 1;
      }
      minor.matrix_[n][m] = this->matrix_[n + row_shift][m + col_shift];
    }
    col_shift = 0;
  }
}
