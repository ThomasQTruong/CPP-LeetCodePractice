/*
 * Test.cpp
 * Used to test out SimplifyPath.cpp.
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#include "SimplifyPath.h"

int main(void) {
  Solution s = Solution();

  std::vector<std::string> hello = s.split("hello//world//", '/');

  for (int i = 0; i < hello.size(); i++) {
    std::cout << hello[i] << std::endl;
  }

  return 0;
}
