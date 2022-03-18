/*
 * SimplifyPath.cpp
 * Solution for the problem:
 * https://leetcode.com/problems/simplify-path/
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#include "SimplifyPath.h"

// 2 ideas:
  // 1. scan for '/' and read for ".." or '.' and determine step.
  // 2. split by '/' and do stuff...

std::string Solution::simplifyPath(std::string path) {
  // Path is empty, just in the home directory.
  if (path == "" || path == "/") {
    return "/";
  }
}

std::vector<std::string> Solution::stringSplit(std::string original, char splitBy) {
  std::vector<std::string> test;
  test.push_back("hello");
  test.push_back("hi");

  return test;
}
