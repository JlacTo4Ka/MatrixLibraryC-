#pragma once

#include <exception>

namespace MyExceptions {
class OperatorBrackets : public std::exception {
 public:
  const char* what() const noexcept override;
};

class CalcComplements : public std::exception {
 public:
  const char* what() const noexcept override;
};

class Constructor : public std::exception {
 public:
  const char* what() const noexcept override;
};

class NullPtr : public std::exception {
 public:
  const char* what() const noexcept override;
};

class DivisionZero : public std::exception {
 public:
  const char* what() const noexcept override;
};

class MultSize : public std::exception {
 public:
  const char* what() const noexcept override;
};

class OutOfRange : public std::exception {
 public:
  const char* what() const noexcept override;
};

};  // namespace MyExceptions