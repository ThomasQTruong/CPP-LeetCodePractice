/*
 * SimplifyPath.h
 * Simple declaration file that doesn't really do much.
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#ifndef _TT_SimplifyPath_H_
#define _TT_SimplifyPath_H_

#include <string>
#include <queue>
#include <deque>
#include <iostream>

class Solution {
 public:
  std::string simplifyPath(std::string path);
  std::queue<std::string> split(std::string toSplit, char splitBy);
  std::string substring(std::string str, int start, int end);
};

#endif  // _TT_SimplifyPath_H_
