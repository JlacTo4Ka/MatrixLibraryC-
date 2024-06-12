#include "../s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  double **new_matrix = new double *[rows];

  for (int i = 0; i < rows; i++) {
    new_matrix[i] = new double[cols_];

    for (int j = 0; j < cols_; j++) {
      if (i < rows_) {
        new_matrix[i][j] = matrix_[i][j];
      } else {
        new_matrix[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = new_matrix;
  rows_ = rows;
}

void S21Matrix::SetCols(int cols) {
  double **new_matrix = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    new_matrix[i] = new double[cols];

    for (int j = 0; j < cols; j++) {
      if (j < cols_) {
        new_matrix[i][j] = matrix_[i][j];
      } else {
        new_matrix[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  matrix_ = new_matrix;
  cols_ = cols;
}