/**
 * Problem Origin: Leetcode
 * Problem Name: Contains Duplicate
 * Problem No: 217
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/contains-duplicate/description/
 * 
 * Problem Description: Given an integer array nums, return true if any value appears
 * at least twice in the array, and return false if every element is distinct.
 *
 * Examples:
 *   1. Example 1:
 *      Input: nums = [1,2,3,1]
 *      Output: true
 *      Explanation: The element 1 occurs at the indices 0 and 3.
 *   2. Example 2:
 *      Input: nums = [1,2,3,4]
 *      Output: false
 *      Explanation: All elements are distinct.
 *   3. Example 3:
 *      Input: nums = [1,1,1,3,3,4,3,2,4,2]
 *      Output: true
 * 
 * Constraints:
 *   1 <= nums.length <= 105
 *   -109 <= nums[i] <= 109
 * 
 * Language: C++
 * Approaches:
 *   # Approach 1 (containsDuplicateUsingSet): Unordered Set
 *       1. Traverse the array and keep every value seen so far in a hash set.
 *       2. If the current value is already in the set, a duplicate exists: return true.
 *       3. Otherwise insert it and continue.
 *       4. If the loop ends without a hit, all elements are distinct: return false.
 *     Time Complexity:  O(n) - one pass, O(1) average per lookup/insert
 *     Space Complexity: O(n) - the set can hold up to n distinct values
 *
 *   # Approach 2 (containsDuplicate): By Sorting
 *       1. Sort the array so equal values become adjacent.
 *       2. Compare each element with its previous one.
 *       3. If any adjacent pair is equal, return true; otherwise return false.
 *     Time Complexity:  O(n log n) - dominated by the sort
 *     Space Complexity: O(1) extra (O(log n) for std::sort's recursion stack);
 *                       note that nums is modified (sorted) in place
 *
 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Unordered Set
    bool containsDuplicateUsingSet(vector<int>& nums) {
      // Set of values seen so far
      unordered_set<int> un;
      for(int i = 0; i < nums.size(); i++) {
        // Already seen: duplicate found
        if(un.find(nums[i]) != un.end()) return true;
        un.emplace(nums[i]);
      }
      // No value repeated
      return false;
    }

    // Approach 2: Sorting
    bool containsDuplicate(vector<int>& nums) {
      // After sorting, equal values sit next to each other
      sort(nums.begin(), nums.end());
      for(int i = 1; i < nums.size(); i++) {
          // Adjacent equal pair means a duplicate
          if(nums[i] == nums[i-1]) return true;
      }
      // No value repeated
      return false;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,3,1};

  cout << "Contains Duplicate:" << sol.containsDuplicate(nums) << endl;
  return 0;
}