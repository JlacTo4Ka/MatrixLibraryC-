#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.GetRows()) {
    throw MyExceptions::MultSize();
  }

  S21Matrix result = S21Matrix(this->rows_, other.GetCols());

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      double res = 0;
      for (int k = 0; k < this->cols_; k++) {
        res += this->matrix_[i][k] * other.matrix_[k][j];
      }
      result(i, j) = res;
    }
  }

  *this = result;
}