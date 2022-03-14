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
    switch (s[i]) {
      // If character[i] is a closing parentheses.
      case ')':
      case '}':
      case ']':
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
      break;

      // If character[i] is an opening parentheses.
      case '(':
      case '{':
      case '[':
        // Add to vector.
        parentheses.push_back(s[i]);
      break;
      }
    }
  return true;
}
