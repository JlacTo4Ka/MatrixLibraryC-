#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool res = true;

  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    res = false;
  }

  for (int i = 0; i < this->rows_ && res; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (labs(this->matrix_[i][j] - other.matrix_[i][j]) > EPSILON)
        res = false;
    }
  }

  return res;
}