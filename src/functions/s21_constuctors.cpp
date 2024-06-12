#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;

  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;
  } else {
    throw MyExceptions::Constructor();
  }

  matrix_ = new double*[rows_];

  if (matrix_ == nullptr) {
    throw MyExceptions::NullPtr();
  }

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];

    if (matrix_[i] == nullptr) {
      throw MyExceptions::NullPtr();
    }
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;

  this->matrix_ = new double*[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_];
  }

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}