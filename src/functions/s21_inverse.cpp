#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();

  if (labs(determinant) < EPSILON ||
      (rows_ == 1 && labs(matrix_[0][0]) < EPSILON)) {
    throw MyExceptions::DivisionZero();
  }

  S21Matrix res(*this);
  if (rows_ == 1) {
    res.matrix_[0][0] = 1 / res.matrix_[0][0];
  }

  if (rows_ != 1) {
    res = res.CalcComplements().Transpose();

    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        res.matrix_[i][j] /= determinant;
      }
    }
  }

  return res;
}
