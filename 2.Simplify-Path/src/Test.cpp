/*
 * Test.cpp
 * Used to test out SimplifyPath.cpp.
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#include "SimplifyPath.h"
#include <cstdio>

// Function prototype - (EQ)ual.
bool EQ(std::string got, std::string expect);

int main(void) {
  Solution s = Solution();

  // The parameters to use to test.
  std::string params[] = {"hello/world", "/home//foo/", "/home/", "/../",
                          "/home//foo", "/./././/.//./././/////.////././",
                          "", "/", "/../../..", "/home////////////////hi",
                          "hello////////////", "hello/................",
                          "hello/................/"};
  // The expected returns.
  std::string expect[] = {"/hello/world", "/home/foo", "/home", "/",
                          "/home/foo", "/",
                          "/", "/", "/", "/home/hi",
                          "/hello", "/hello/................",
                          "/hello/................"};

  int success = 0;
  int sizeOfParams = sizeof(params) / sizeof(params[0]);

  // Test params.
  for (int i = 0; i < sizeOfParams; ++i) {
    if (EQ(s.simplifyPath(params[i]), expect[i])) {
      success++;
    } else {
      // Unexpected param.
      std::cout << "Got: " << s.simplifyPath(params[i])
                << " | Expected: " << expect[i] << " | i = " << i << std::endl;
    }
  }

  printf("Score: %i/%i.\n", success, sizeOfParams);

  return 0;
}

bool EQ(std::string got, std::string expect) {
  return got == expect;
}
