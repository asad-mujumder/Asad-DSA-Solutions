/**
 * Problem Origin: Leetcode
 * Problem No: 844
 * Problem Name: Backspace String Compare
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/backspace-string-compare/description/
 * 
 * Problem Description: Given two strings s and t, return true if they are equal when
 * both are typed into empty text editors. '#' means a backspace character.
 * 
 * Note that after backspacing an empty text, the text will continue empty.
 *
 * Examples:
 *   1. Example 1:
 *      Input: s = "ab#c", t = "ad#c"
 *      Output: true
 *      Explanation: Both s and t become "ac".
 *   2. Example 2:
 *      Input: s = "ab##", t = "c#d#"
 *      Output: true
 *      Explanation: Both s and t become "".
 *   3. Example 3:
 *      Input: s = "a#c", t = "b"
 *      Output: false
 *      Explanation: s becomes "c" while t becomes "b".
 * 
 * Constraints:
 *   1 <= s.length, t.length <= 200
 *   s and t only contain lowercase letters and '#' characters.
 * 
 * Language: C++
 * Approaches:
 *   # Approach 1 (backspaceCompareWithErase): Using erase() method of string
 *       1. Scan s from left to right.
 *       2. On '#', erase it together with the character before it (just the '#' if it
 *          is at index 0, since there is nothing to delete), then step the index back
 *          so the next unchecked character is not skipped.
 *       3. Repeat the same process for t.
 *       4. Both strings now hold their final typed text: return s == t.
 * 
 *     Time Complexity:  O(n^2) - each erase() shifts the remaining characters, O(n)
 *     Space Complexity: O(n) - s and t are passed by value (copies)
 *
 *   # Approach 2 (backspaceCompare): Two Pointers from the end
 *       1. Start one pointer at the end of each string and walk backwards.
 *       2. Use the helper to skip characters that are erased: count each '#', and
 *          let every non-'#' character cancel one pending backspace. The first
 *          character that survives is the next valid character.
 *       3. If both pointers ran out (< 0), everything matched: return true.
 *       4. If only one ran out, or the valid characters differ, return false.
 *       5. Otherwise move both pointers one step left and repeat.
 * 
 *     Time Complexity:  O(n + m) - each pointer moves left at most once per character
 *     Space Complexity: O(1) - no extra buffers (requires the helper to take
 *                       const string& instead of a copy, see note below)
 *
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    // Returns the index of the closest valid (not erased) character at or before `end`,
    // or -1 if none exists
    int get_next_valid_char_index(string str, int end) {
      int backspaceCount = 0; // pending backspaces waiting to erase a character
      while(end >= 0) {
        if(str[end] == '#') {
          backspaceCount++;      // a backspace: it will erase one char to its left
        } else if(backspaceCount > 0) {
          backspaceCount--;      // normal char erased by a pending backspace
        } else {
          break;                 // normal char with no pending backspace: valid
        }
        end--;
      }
      return end;
    }
public:
    // Approach 1: Using erase() method of string
    bool backspaceCompareWithErase(string s, string t) {
        // Process s: remove every '#' along with the character it deletes
        for(int i = 0; i < s.length(); i++) {
            if(s == "") break; // nothing left to process
            if(s[i] == '#') {
                if(i == 0) {
                  // Backspace on empty text: only the '#' itself is removed
                  s.erase(0, 1);
                  i = -1; // loop's i++ brings it back to index 0
                } else {
                  // Remove the previous char and the '#'
                  s.erase(i-1, 2);
                  i -= 2; // net effect after i++: continue from the char that shifted into i-1
                }
            }
        }

        // Process t with the same logic
        for(int i = 0; i < t.length(); i++) {
            if(t == "") break;
            if(t[i] == '#') {
                if(i == 0) {
                  t.erase(0, 1);
                  i = -1;
                } else {
                  t.erase(i-1, 2);
                  i -= 2;
                }
            }
        }

        // Both are now the final typed text
        return s == t;
    }

    // Approach 2: Two Pointers from the end
    bool backspaceCompare(string s, string t) {
      // Pointers start at the last character of each string
      int ps = s.length() - 1;
      int pt = t.length() - 1;

      while(ps>= 0 || pt>=0) {
        // Move each pointer to its next character that survives the backspaces
        ps = get_next_valid_char_index(s, ps);
        pt = get_next_valid_char_index(t, pt);

        if(ps < 0 && pt < 0) {
          // Both strings exhausted at the same time: they are equal
          return true;
        } else if((ps < 0 || pt < 0) || (s[ps] != t[pt])) {
          // Only one exhausted, or valid characters differ
          return false;
        }

        // Characters matched: move to the next pair
        ps--;
        pt--;
      }
      return true;
    }
};

int main() {
  Solution sol;
  cout << (sol.backspaceCompare("ab#c", "ad#c") ? "Similar" : "Not Similar") << endl;
  return 0;
}