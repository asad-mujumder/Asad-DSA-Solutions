/*
# Problem Origin: Leetcode
# Problem Name: Valid Palindrome
# Problem No: 125
# Difficulty: Medium
# Problem Link: https://leetcode.com/problems/valid-palindrome/description/
# Problem Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase
letters and removing all non-alphanumeric characters, it reads the same forward and
backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
  1. 1 <= s.length <= 2 * 105
  2. s consists only of printable ASCII characters.

# Note For LeetCode:
 1. You don't need to import any library. For example, "#include<iostream>" is not needed
 2. No need to specify namespace
 3. No need to write the main function or input or output any value
 4. Only need to write the solution within the function provided. (Here between "solution - Start" and "solution - End")

# ***** Best Solution *****: Under the comment "Main Solution"
*/
#include<iostream>
#include <cctype> // needed only for static_cast<unsigned char>(To avoid undefined behaviour for negative char values)
using namespace std;

/*
  SOLUTION 1: With static_cast<unsigned char> to avoid undefined behaviour for negative char values
  Time Complexity: O(n) 
  - Each character is visited at most once from either end.
  - Operations inside the loop (isalnum, tolower, comparisons) are O(1).
  - Total = O(n), where n = s.length().

  Space Complexity: O(1) 
  - Uses only a few integer variables (left, right).
  - No extra data structures.
*/
bool isPalindromeWithStaticCast(string s) {
   /* solution - Start */

  // 1. Initialize two pointers
  int left = 0;
  int right = (int)s.length() - 1;
  // left  -> starts from the beginning of the string (index 0)
  // right -> starts from the end (last index)

  while (left < right) {
    // 2. Move pointers towards the center while comparing valid characters

    if (!isalnum(static_cast<unsigned char>(s[left]))) {
      // 2a. Skip non-alphanumeric characters on the left side
      // Use static_cast<unsigned char> to avoid undefined behaviour for negative char values.
      // s[left] is not a letter or digit (could be punctuation, space, etc.)
      // Move left pointer forward to find the next alphanumeric character.
      left++;
    }
    else if (!isalnum(static_cast<unsigned char>(s[right]))) {
      // 2b. Skip non-alphanumeric characters on the right side
      // s[right] is not a letter or digit — move right pointer backward.
      right--;
    }
    else if (tolower(static_cast<unsigned char>(s[left])) !=
             tolower(static_cast<unsigned char>(s[right]))) {
      // 2c. Both s[left] and s[right] are alphanumeric — compare them case-insensitively
      // If the normalized characters don't match, `s` is not a palindrome.
      return false;
    }
    else {
      // 2d. Characters match — move both pointers inward to check the next pair
      left++;
      right--;
    }
  }

  // 3. If we completed the loop without returning false, the string is a palindrome
  return true;

  /* solution - End */
}

/* ------------------------ Main Solution ------------------------ */
/*
  SOLUTION 2: Optimal Solution
  Time Complexity: O(n) 
  - Each character is visited at most once from either end.
  - Operations inside the loop (isalnum, tolower, comparisons) are O(1).
  - Total = O(n), where n = s.length().

  Space Complexity: O(1) 
  - Uses only a few integer variables (left, right).
  - No extra data structures.
*/
bool isPalindrome(string s) {
   /* solution - Start */

  // 1. Initialize two pointers for comparison
  int left = 0, right = s.length() - 1;
  // left  -> starts at the beginning of the string
  // right -> starts at the end of the string

  while (left < right) {
    // 2. Process characters while left index is before right index
    
    if (!isalnum(s[left])) {
      // 2a. Skip non-alphanumeric characters from the left side
      left++;
    } else if (!isalnum(s[right])) {
      // 2b. Skip non-alphanumeric characters from the right side
      right--;
    } else if (tolower(s[left]) != tolower(s[right])) {
      // 2c. Both characters are alphanumeric, check case-insensitive match
      // If they don’t match, string is not a palindrome
      return false;
    } else {
      // 2d. Characters matched, move both pointers inward
      left++;
      right--;
    }
  }

  // 3. If loop finishes without mismatch, string is a palindrome
  return true;

  /* solution - End */
}

int main () {
  string s;
  getline(cin, s);

  string result = isPalindrome(s) ? "True" : "False";
  cout << result;
  
  return 0;
}