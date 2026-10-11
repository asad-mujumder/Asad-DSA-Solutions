/*
# Problem Origin: Leetcode
# Problem Name: Palindrome Number
# Problem No: 9
# Difficulty: Easy
# Problem Link: https://leetcode.com/problems/palindrome-number/description/
# Problem Description:
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
  1. -231 <= x <= 231 - 1
 
Follow up: Could you solve it without converting the integer to a string?

# Note For LeetCode:
 1. You don't need to import any library. For example, "#include<iostream>" is not needed
 2. No need to specify namespace
 3. No need to write the main function or input or output any value
 4. Only need to write the solution within the function provided. (Here between "solution - Start" and "solution - End")

# ***** Best Solution *****: Under the comment "Main Solution"
*/
#include<iostream>
using namespace std;

/*  
  SOLUTION 1: Secondary Solution Using String
  Time Complexity: O(n) 
  - Converting an integer to a string takes O(n), where n is the number of digits.
  - The for loop runs for n/2 iterations, which is O(n).

  Space Complexity: O(n) 
  - The string representation of x takes O(n) space.
  - No additional data structures are used apart from the string.
*/
bool isPalindromeByString(int x) {
  /* solution - Start */

  // 1. Handle edge case for negative numbers
  if(x < 0) return false;
  // Negative numbers are not palindromes.

  // 2. Convert the number to a string
  string num = to_string(x);
  // This converts the integer x into its string representation.

  // 3. Compare characters from both ends moving towards the center
  for(int i = 0; i < num.length() / 2; i++) {
    if(num[i] != num[num.length() - 1 - i]) return false;
    // If any pair of characters from the start and end don't match, return false.
  } // End of for loop

  // 4. If all characters matched, return true
  return true;
  // The number is a palindrome.

  /* solution - End */
}

/* ------------------------ Main Solution ------------------------ */
/*  
  SOLUTION 2: Optimized Solution Using Half Reversal
  Time Complexity: O(log₁₀(n)) 
  - We reduce x by a factor of 10 in each iteration.
  - The number of digits in x is log₁₀(n), so the loop runs O(log₁₀(n)) times.

  Space Complexity: O(1) 
  - Only a few integer variables (x, rev) are used.
  - No additional data structures are required.
*/
bool isPalindrome(int x) {
  /* solution - Start */

  // 1. Handle edge cases
  if(x < 0 || (x != 0 && x % 10 == 0)) return false;
  // Negative numbers are not palindromes.
  // Numbers ending in 0 (except 0 itself) are not palindromes.

  // 2. Initialize a variable to store the reversed half of the number
  int rev = 0; // This will store the reversed digits of half the number.

  // 3. Reverse half of the number
  while (x > rev) {
      rev = 10 * rev + x % 10;
      // x % 10 extracts the last digit of x.
      // 10 * rev shifts the existing digits left by one place.
      // Adding x % 10 appends the last digit to rev.

      x /= 10;
      // This removes the last digit from x, moving to the next one.
  } // End of while loop

  // 4. Check if the number is a palindrome
  return x == rev || x == rev / 10;
  // If x == rev, it means the number has an even number of digits (e.g., 1221).
  // If x == rev / 10, it means the number has an odd number of digits (e.g., 12321).
  // rev / 10 removes the middle digit, which isn't needed for the comparison.

  /* solution - End */
}


int main () {
  int x;
  cin >> x;
  string ans = isPalindrome(x) ? "True" : "False";
  cout << ans;
  return 0;
}