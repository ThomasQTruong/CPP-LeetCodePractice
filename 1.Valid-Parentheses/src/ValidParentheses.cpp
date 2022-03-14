/*
* ValidParentheses.cpp
* File that contains the solution for:
* https://leetcode.com/problems/valid-parentheses/
*
* Copyright (c) 2022, Thomas Truong.
*/

#include "ValidParentheses.h"

bool Solution::isValid(std::string s) {
  std::vector<char> parentheses;

  // For every character in the string, s.
  for (int i = 0; i < s.length(); i++) {
    // If character[i] is an opening parentheses.
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      // Add to vector and continue.
      parentheses.push_back(s[i]);
      continue;
    }

    // If character[i] is a closing parentheses.
    if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
      // Nothing to close!!
      if (parentheses.empty()) {
        return false;
      }

      // Checks if closing parentheses does not match the current parentheses.
      if (s[i] == ')' && parentheses.back() != '(') {
        return false;
      } else if (s[i] == '}' && parentheses.back() != '{') {
        return false;
      } else if (s[i] == ']' && parentheses.back() != '[') {
        return false;
      } else {
        // Closing parentheses matches; remove the current parentheses from vector.
        parentheses.pop_back();
      }
    }
  }
  return true;
}
