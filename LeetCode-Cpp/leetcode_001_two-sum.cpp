/**
 * Problem Origin: Leetcode
 * Problem No: 001
 * Problem Name: Two Sum
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/two-sum/description/
 * 
 * Problem Description: You are given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use
 * the same element twice.
 * 
 * You can return the answer in any order.
 *
 * Examples:
 *   1. Example 1:
 *      Input: nums = [2,7,11,15], target = 9
 *      Output: [0,1]
 *      Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *   2. Example 2:
 *      Input: nums = [3,2,4], target = 6
 *      Output: [1,2]
 *   3. Example 3:
 *      Input: nums = [3,3], target = 6
 *      Output: [0,1]
 * 
 * Constraints:
 *   2 <= nums.length <= 104
 *   -109 <= nums[i] <= 109
 *   -109 <= target <= 109
 *   Only one valid answer exists.
 * 
 * Language: C++
 * Approaches:
 *   # Approach 1 (twoSum): Unordered Map
 *       1. Keep a hash map of value -> index for the elements visited so far.
 *       2. For each nums[i], compute its complement: target - nums[i].
 *       3. If the complement is already in the map, we found the pair: return
 *           {index of complement, i}.
 *       4. Otherwise store nums[i] -> i and continue.
 *       Inserting after the lookup guarantees the same element is never used twice.
 *       
 *       Time Complexity:  O(n) - single pass, O(1) average per lookup/insert
 *       Space Complexity: O(n) - the map can hold up to n entries
 *
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Hash Map (one pass)
    vector<int> twoSum(vector<int>& nums, int target) {
      // Map: value -> index of that value among the elements visited so far
      unordered_map<int,int> mp;

      for(int i = 0; i < nums.size(); i++) {
        // Look for the number that completes the sum with nums[i]
        auto it = mp.find((target - nums[i]));
        if(it != mp.end()) {
          // Complement seen earlier: return its index and the current index
          return {it->second,i};
          // return {(*it).second, i};
        }
        // Not found: remember the current value (after the lookup, so an
        // element is never paired with itself)
        mp[nums[i]] = i;
      }

      // Unreachable: exactly one solution is guaranteed
      return {-1,-1};
    }
};

int main(){
  Solution sol;
  vector<int> nums = {2,7,11,15};
  int target = 9;

  vector<int> result = sol.twoSum(nums, target);

  cout << "Indexes: {" << result[0] << "," << result[1] << '}' << endl;
  return 0;
}