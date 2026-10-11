/*
# Problem Origin: Leetcode
# Problem Name: Reverse Integer
# Problem No: 7
# Difficulty: Easy
# Problem Link: https://leetcode.com/problems/reverse-integer/description/
# Problem Description:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

# Note For LeetCode:
 1. You don't need to import any library. For example, "#include<iostream>" is not needed
 2. No need to specify namespace
 3. No need to write the main function or input or output any value
 4. Only need to write the solution within the function provided. (Here between "solution - Start" and "solution - End")

# ***** Best Solution *****: Under the comment "Main Solution"
*/
#include<iostream>
#include <climits>
using namespace std;

/* ------------------------ Main Solution ------------------------ */
/*  
  Time Complexity: O(log₁₀(n)) 
  - The number of digits in x is log₁₀(n).
  - The while loop processes each digit once, leading to O(log₁₀(n)) time complexity.

  Space Complexity: O(1) 
  - Only a few integer variables (x, r) are used.
  - No additional data structures are required.
*/
int reverse(int x) {
  /* solution - Start */

  // 1. Initialize a variable to store the reversed number
  int r = 0; // This will store the reversed digits.

  // 2. Loop while x is not zero
  while (x != 0) { 
    // 3. Check for integer overflow/underflow before updating r
    if (r > INT_MAX / 10 || r < INT_MIN / 10) return 0;
    // This prevents r from exceeding the 32-bit integer range when multiplied by 10.

    // 4. Extract the last digit of x and add it to r
    r = 10 * r + x % 10;
    // x % 10 extracts the last digit of x.
    // 10 * r shifts the existing digits left by one place.
    // Adding x % 10 appends the last digit to r.

    // 5. Remove the last digit from x
    x /= 10;
    // This discards the last digit of x, moving to the next one.
   } // End of while loop

  // 6. Return the reversed integer
  return r;
  // If the number was out of bounds, it returns 0 to prevent overflow.

  /* solution - End */
}

int main() {
  int n;
  cin >> n;
  cout << "Number: " << n << endl << "Reverse: " << reverse(n);
  return 0;
}