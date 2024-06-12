#include "exception.h"

const char* MyExceptions::OperatorBrackets::what() const noexcept {
  return "Operator '()' error: incorrect size\n";
};

const char* MyExceptions::CalcComplements::what() const noexcept {
  return "Calc complements error: size\n";
};

const char* MyExceptions::Constructor::what() const noexcept {
  return "Constructor error: count of rows and/or cols have to be greater "
         "zero\n";
};

const char* MyExceptions::NullPtr::what() const noexcept {
  return "The pointer to null: Incorrect memory allocation\n";
};

const char* MyExceptions::DivisionZero::what() const noexcept {
  return "Division by zero\n";
};

const char* MyExceptions::MultSize::what() const noexcept {
  return "MultSize error: Incorrect input, number of cols of first matrice "
         "should has the same number of rows second\n";
};

const char* MyExceptions::OutOfRange::what() const noexcept {
  return "Sum or sub error: Incorrect input, matrices should have the same "
         "size\n";
};
