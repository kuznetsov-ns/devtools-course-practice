// Copyright 2021 Kuznetsov Nikita

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_

#include <string>

class BitArrayApplication {
 public:
  BitArrayApplication() = default;
  std::string operator()(int argc, const char* argv[]) const;
 private:
  std::string help(const std::string& filename) const;
  int checkPositiveNumber(const char* argv) const;
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
