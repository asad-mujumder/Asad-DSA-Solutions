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
 *       1. 
 *
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: 
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mp;

      for(int i = 0; i < nums.size(); i++) {
        auto it = mp.find((target - nums[i]));
        if(it != mp.end()) {
          return {it->second,i};
          // return {(*it).second, i};
        }
        mp[nums[i]] = i;
      }

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