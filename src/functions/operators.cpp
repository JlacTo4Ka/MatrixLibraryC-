#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] matrix_;

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
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.SumMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.SubMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.MulMatrix(other);
  return temp;
}
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix temp(*this);
  temp.MulNumber(num);
  return temp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_) {
    throw MyExceptions::OperatorBrackets();
  }

  return this->matrix_[i][j];
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_) {
    throw MyExceptions::OperatorBrackets();
  }

  return this->matrix_[i][j];
}
