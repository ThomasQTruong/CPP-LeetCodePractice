/*
 * SimplifyPath.cpp
 * Solution for the problem:
 * https://leetcode.com/problems/simplify-path/
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#include "SimplifyPath.h"

std::string Solution::simplifyPath(std::string path) {
  // Path is empty, just in the home directory.
  if (path == "" || path == "/") {
    return "/";
  }

  // Path did not start with a '/' so add it.
  if (path[0] != '/') {
    path = '/' + path;
  }
}
