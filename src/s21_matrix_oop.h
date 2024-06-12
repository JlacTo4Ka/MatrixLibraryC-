#pragma once

#include <iostream>

#include "exception/exception.h"

#define EPSILON 0.000001
class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  /* --------------- конструкторы: базовый, параметризированный, копирования и
   * переноса --------------- */
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  /* --------------- accessor и mutator (геттер и сеттер соответственно)
   * --------------- */
  int GetRows() const;
  int GetCols() const;

  void SetRows(int rows);
  void SetCols(int cols);

  /* --------------- методы класса --------------- */
  bool EqMatrix(const S21Matrix& other);  // сравнение

  void SumMatrix(const S21Matrix& other);  // сложение

  void SubMatrix(const S21Matrix& other);  // вычитание

  void MulNumber(const double num);  // умножение на число

  void MulMatrix(const S21Matrix& other);  // умножение матриц

  S21Matrix Transpose();  // транспонирование

  S21Matrix CalcComplements();  // алг дополнения

  double Determinant();  // детерминант
  double FindDeterminant();
  double GetMinor(int i, int j);
  void FillMinor(int i, int j, S21Matrix& minor);

  S21Matrix InverseMatrix();  // обратная

  /* --------------- вспомогательные функции --------------- */

  void Print();
  void SetIJ(int i, int j, double value);

  /* --------------- операторы --------------- */
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);
  double& operator()(int i, int j) const;
  /* --------------- деструктор --------------- */
  ~S21Matrix();
};
