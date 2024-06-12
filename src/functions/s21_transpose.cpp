#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(cols_, rows_);

  for (int i = 0; i < temp.GetRows(); i++) {
    for (int j = 0; j < temp.GetCols(); j++) {
      temp.matrix_[i][j] = this->matrix_[j][i];
    }
  }

  return temp;
}