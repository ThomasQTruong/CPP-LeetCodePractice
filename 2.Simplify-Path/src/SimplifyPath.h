/*
 * SimplifyPath.h
 * Simple declaration file that doesn't really do much.
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#ifndef _TT_SimplifyPath_H_
#define _TT_SimplifyPath_H_

#include <string>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(std::string path);
  std::vector<std::string> stringSplit(std::string original, char splitBy);
};

#endif  // _TT_SimplifyPath_H_
