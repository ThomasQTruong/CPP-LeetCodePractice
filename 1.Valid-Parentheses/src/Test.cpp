/*
 * Test.cpp
 * Used for testing ValidParentheses.cpp.
 *
 * Copyright (c) 2022, Thomas Truong.
 */

#include "ValidParentheses.h"
#include <iostream>

int main(void) {
  Solution test = Solution();
  int success = 0;

  // Values used for testing.
  std::string testCases[] = {"[(){([])}]", "[(){([)}]", "[]", "()", "{}", "(]", "[}", "}{", ")(",
                           "(((){{{}[[]]}}))", "[[()]]", "(((){{{}[[])}})}"};
  // Expected return for the values above.
  bool expected[] = {true, false, true, true, true, false, false, false, false,
                     true, true, false};

  // Test cases.
  for (int i = 0; i < sizeof(expected) / sizeof(expected[0]); i++) {
    if (test.isValid(testCases[i]) != expected[i]) {
      // Did not match, solution invalid.
      std::cout << "isValid(" << testCases[i] << ") = " << ((expected[i]) ? "false" : "true")
                << ", expected " << ((expected[i]) ? "true" : "false") << "." << std::endl;
    } else {
      // Count successes.
      success++;
    }
  }

  // Print score.
  std::cout << "Score: " << success << "/" << sizeof(expected) / sizeof(expected[0]) << std::endl;
}
