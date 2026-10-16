/**
 * Problem Origin: Leetcode
 * Problem Name: Valid Anagram
 * Problem No: 242
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/valid-anagram/description/
 * 
 * Problem Description: Given two strings s and t, return true if t is an
 * anagram of s, and false otherwise.
 *
 * Examples:
 *   1. Example 1:
 *      Input: s = "anagram", t = "nagaram"
 *      Output: true
 *   2. Example 2:
 *      Input: s = "rat", t = "car"
 *      Output: false
 * 
 * Constraints:
 *   1 <= s.length, t.length <= 5 * 104
 *   -s and t consist of lowercase English letters.
 * 
 * Language: C++
 * Approaches:
 *   # Approach 1 (isAnagramUsingMap): Using "Unordered Map"
 *       1. If the strings are equal, return true; if their lengths differ, return false.
 *       2. Build a frequency map of characters for s and another for t.
 *       3. For every (char, count) in s's map, look the char up in t's map.
 *       4. If the char is missing or its count differs, return false.
 *       5. If all entries match, the strings are anagrams: return true.
 *     Time Complexity:  O(n) - one pass over each string, O(1) average per map operation
 *     Space Complexity: O(k) - k = number of distinct characters (k <= 26 here, so O(1))
 *
 *   # Approach 2 (isAnagram): Using Array of size 26 (for each of 26 english letters)
 *       1. If the strings are equal, return true; if their lengths differ, return false.
 *       2. Use an int array of size 26 as a frequency table, index = ch - 'a'.
 *       3. Increment the count for every character of s.
 *       4. Decrement the count for every character of t; if a count drops below 0,
 *          t has a character that s does not have enough of: return false.
 *       5. Since both lengths are equal, no count can be left positive when none went
 *          negative, so return true.
 *     Time Complexity:  O(n) - one pass over each string
 *     Space Complexity: O(1) - fixed array of 26 integers
 *     Note: relies on lowercase letters only. For Unicode input (the follow-up),
 *           use a hash map (Approach 1) instead.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Using "Unordered Map" - Works for "Unicode" too
    bool isAnagramUsingMap(string s, string t) {
      // Identical strings are trivially anagrams
      if(s == t) return true;
      // Anagrams must have the same length
      if(s.length() != t.length()) return false;

      // Frequency maps: char -> number of occurrences
      unordered_map<char,int> ums;  // for s
      unordered_map<char,int> umt;  // for t
      for(const char& ch:s) {
        ums[ch]++;
      }
      for(const char& ch:t) {
        umt[ch]++;
      }

      // Every char in s must appear in t with the exact same count
      for(const auto& ms:ums) {
        auto mt = umt.find(ms.first);
        // Missing char or different count -> not an anagram
        if(mt == umt.end() || (*mt).second != ms.second) return false;
      }
      return true;
    }

    // Approach 2: Using Array of size 26(for each of 26 english letters)
    bool isAnagram(string s, string t) {
      // Identical strings are trivially anagrams
      if(s == t) return true;
      // Anagrams must have the same length
      if(s.length() != t.length()) return false;

      // arr[i] = count of the i-th letter ('a' -> 0, ..., 'z' -> 25)
      int arr[26] = {};
      // Count letters of s
      for(char ch:s) arr[ch-'a']++;
      // Cancel out letters of t; a negative count means t has an extra
      // occurrence of that letter that s does not have
      for(char ch:t) if(--arr[ch-'a'] < 0) return false;
      // Alt: single pass, then check that all counts are back to zero
      // for(int i = 0; i < s.length(); i++) {
      //   arr[s[i] - 'a']++;
      //   arr[t[i] - 'a']--;
      // }
      // for(int i = 0; i < 26; i++) {
      //   if(arr[i] != 0) return false;
      // }
      // Equal lengths + no negative count => all counts are zero
      return true;
    }
};

int main(){
  Solution sol;
  string s = "anagram";
  string t = "nagaram";

  cout << "Is Anagram: " << ((sol.isAnagramUsingMap(s,t) == 1) ? "True" : "False" )<< endl;
  return 0;
}