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

  // Splits the string whenever there is the '/' character.
  std::queue<std::string> splitted = split(path, '/');
  std::deque<std::string> regularPath;

  std::string newPath = "";  // Contains the new path.
  while (splitted.size() > 0) {
    // If splitted.front() contains nothing or "." then remove from queue.
    if (splitted.front() == "" || splitted.front() == ".") {
      splitted.pop();
      continue;
    }

    // If splitted.front() contains the back function ("..").
    if (splitted.front() == "..") {
      // Remove item at back if there is something to remove.
      if (regularPath.size() > 0) {
        regularPath.pop_back();
      }
      splitted.pop();
      continue;
    }

    // Nothing wrong with the path, add to back to regularPath.
    regularPath.push_back(splitted.front());
    splitted.pop();
  }

  // Nothing to add to the path.
  if (regularPath.size() == 0) {
    return "/";
  }

  // Add everything from regularPath to newPath.
  while (regularPath.size() > 0) {
    newPath += "/" + regularPath.front();
    regularPath.pop_front();
  }

  return newPath;
}


/**
 * Splits a given string by a character.
 *
 * @param toSplit - The string to split.
 * @param splitBy - The character to split the string with.
 * @return std::queue<std::string> - a queue that contains
 *  every value next to given character.
 */
std::queue<std::string> Solution::split(std::string toSplit, char splitBy) {
  std::queue<std::string> splitted;
  int start_index = 0;

  for (int i = 0; i < toSplit.length(); ++i) {
    // character[i] is the same character as splitBy.
    if (toSplit[i] == splitBy) {
      // Add substring to queue and change start_index.
      splitted.push(substring(toSplit, start_index, i));
      start_index = i + 1;
    }

    // Is last index.
    if (i == toSplit.length() - 1) {
      // Add remaining substring.
      splitted.push(substring(toSplit, start_index, i + 1));
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
  // End is going to be out of range, set it to length.
  if (end > str.length()) {
    end = str.length();
  }

  std::string sub = "";
  for (int i = start; i < end; ++i) {
    sub += str[i];
  }

  return sub;
}
