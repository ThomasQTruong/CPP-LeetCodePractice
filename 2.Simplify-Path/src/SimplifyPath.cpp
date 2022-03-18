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
}


/**
 * Splits a given string by a character.
 *
 * @param toSplit - The string to split.
 * @param splitBy - The character to split the string with.
 * @return std::vector<std::string> - a vector that contains
 *  every value next to given character.
 */
std::vector<std::string> Solution::split(std::string toSplit, char splitBy) {
  std::vector<std::string> splitted;
  int start_index = 0;

  for (int i = 0; i < toSplit.length(); i++) {
    // character[i] is the same character as splitBy.
    if (toSplit[i] == splitBy) {
      // Add substring to vector and change start_index.
      splitted.push_back(substring(toSplit, start_index, i));
      start_index = i + 1;
    } else if (i == toSplit.length() - 1) {
      // Is last index, add remaining substring.
      splitted.push_back(substring(toSplit, start_index, i + 1));
    }
  }
  return splitted;
}


/**
 * Retrieves a part of a string based on a given range.
 * 
 * @param str - the string to retrieve a part of.
 * @param start - the starting index.
 * @param end - the ending index (not included).
 * @return std::string - the part of the string retrieved.
 */
std::string Solution::substring(std::string str, int start, int end) {
  // Start is negative, set to 0.
  if (start < 0) {
    start = 0;
  }

  std::string sub = "";
  for (int i = start; i < end; i++) {
    // i is out of range, stop process.
    if (i >= str.length()) {
      break;
    }
    sub += str[i];
  }

  return sub;
}
