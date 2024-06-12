#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_ || this->rows_ == 1) {
    throw MyExceptions::CalcComplements();
  }

  S21Matrix res(rows_, cols_);

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      double temp_res = 0;

      temp_res = this->GetMinor(i, j);

      if ((i + j) % 2 == 0) {
        res.matrix_[i][j] = temp_res;
      } else {
        if (temp_res)
          res.matrix_[i][j] = -temp_res;
        else
          res.matrix_[i][j] = temp_res;
      }
    }
  }

  return res;
}