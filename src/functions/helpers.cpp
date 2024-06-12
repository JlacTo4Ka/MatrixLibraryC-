#include "../s21_matrix_oop.h"

// void S21Matrix::Print() {
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             std::cout << matrix_[i][j] << ' ';
//         }
//         std::cout << '\n';
//     }
// }

void S21Matrix::SetIJ(int i, int j, double value) {
  if (i >= rows_ || j >= cols_) {
    throw std::out_of_range("Set i or j error; i or j greater size matrices");
  }

  this->matrix_[i][j] = value;
}