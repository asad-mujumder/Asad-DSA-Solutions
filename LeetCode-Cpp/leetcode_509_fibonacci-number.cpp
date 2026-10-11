/*
# Problem Origin: Leetcode
# Problem Name: Fibonacci Number
# Problem No: 509
# Difficulty: Easy
# Problem Link: https://leetcode.com/problems/fibonacci-number/description/
# Problem Description:
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
  1. 0 <= n <= 30

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
  SOLUTION 1: Recursive Fibonacci - Naive Solution
  Time Complexity: O(2^n)
  - Each call branches into 2 more calls (n-1, n-2).
  - Leads to exponential growth of calls.
  - Total = O(2^n).

  Space Complexity: O(n)
  - Recursion stack goes as deep as n in the worst case.
  - No extra data structures used.
*/
int fib_rec(int n) {
  /* solution - Start */

  // 1. Base case: return n if 0 or 1
  if (n == 0 || n == 1) return n;

  // 2. Recursive case: sum of two previous Fibonacci numbers
  return fib_rec(n - 1) + fib_rec(n - 2);

  /* solution - End */
}

/* ------------------------ Main Solution ------------------------ */
/*
  SOLUTION 2: Iterative Fibonacci - Optimal Solution
  Time Complexity: O(n)
  - Loop runs from 2 to n → executes (n-1) times.
  - Each iteration does only O(1) operations.
  - Total = O(n).

  Space Complexity: O(1)
  - Only a few integer variables (f, p, t).
  - No extra data structures or recursion stack.
*/
int fib(int n) {
  /* solution - Start */

  // 1. Handle base cases directly
  if (n == 0 || n == 1) return n;

  // 2. Initialize variables
  int f = 1; // f -> current Fibonacci number
  int p = 0; // p -> previous Fibonacci number

  // 3. Iterate from 2 up to n
  for (int i = 2; i <= n; i++) {
    int t = f;   // 3a. Temporarily store current value of f
    f = f + p;   // 3b. Update f to next Fibonacci number
    p = t;       // 3c. Update p to previous Fibonacci number
  }

  // 4. Return the nth Fibonacci number
  return f;

  /* solution - End */
}

int main () {
  int n;
  cin >> n;

  int result = fib(n);
  cout << result << endl;

  return 0;
}