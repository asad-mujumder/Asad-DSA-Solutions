/**
 * Problem Origin: Leetcode
 * Problem Name: Majority Element
 * Problem No: 169
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/majority-element/description/
 * 
 * Problem Description: Given an array nums of size n, return the majority element. 
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * 
 * You may assume that the majority element always exists in the array.
 *
 * Examples:
 *   1. Example 1:
 *      Input: nums = [3,2,3]
 *      Output: 3
 *   2. Example 2:
 *      Input: nums = [2,2,1,1,1,2,2]
 *      Output: 2
 * 
 * Constraints:
 *   n == nums.length
 *   1 <= n <= 5 * 104
 *   -109 <= nums[i] <= 109
 *   The input is generated such that a majority element will exist in the array.
 * 
 * Language: C++
 * Approaches: 
 *   # Approach 1 (majorityElementUsingMap): Hash Map
 *       1. Count the occurrences of each value using a hash map.
 *       2. Return the value whose count is greater than n / 2.
 *     Time Complexity: O(n) - one pass to count, one pass over the map
 *     Space Complexity: O(k) - k = number of distinct values (k <= n)
 *
 *   # Approach 2 (majorityElement): Boyer-Moore Voting Algorithm
 *       1. Keep a candidate and a vote counter. If votes is 0, pick the current
 *          element as the new candidate.
 *       2. If the current element equals the candidate, votes++; otherwise votes--.
 *          Each non-matching pair cancels out, so a true majority element
 *          (> n / 2) always survives as the final candidate.
 *       3. Verification pass: count the candidate's occurrences and confirm it
 *          appears more than n / 2 times (needed only if a majority is not guaranteed).
 *     Time Complexity: O(n) - one pass to find the candidate, one pass to verify
 *     Space Complexity: O(1) - only a few variables
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Hash Map
    int majorityElementUsingMap(vector<int>& nums) {
      // Map: value -> number of times it appears in nums
      unordered_map<int,int> um;
      for(int i = 0; i < nums.size(); i++) {
        um[nums[i]]++;
      }
      // The majority element is the one appearing more than n / 2 times
      for(auto m:um) {
        if(m.second > nums.size() / 2) return m.first;
      }
      return -1; // Unreachable: a majority element is guaranteed to exist
    }

    // Approach 2: Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
      int candidate = -1, votes = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(votes == 0) {
          // No active candidate: adopt the current element
          candidate = nums[i];
          votes = 1;
        } else {
          if(nums[i] == candidate) {
            votes++; // Same as candidate: strengthen it
          } else {
            votes--; // Different: cancels out one vote
          }
        }
      }
      // Verification pass: count occurrences of the surviving candidate
      int count;
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == candidate) count++;
      }
      if(count > nums.size()/2) return candidate;
      return candidate;
    }
};

int main(){
  Solution sol;
  vector<int> nums1 = {3,2,3}; // 3
  vector<int> nums2 = {2,2,1,1,1,2,2}; // 2

  cout << "Majority for nums1:" << sol.majorityElement(nums1) << endl;
  cout << "Majority for nums2:" << sol.majorityElement(nums2) << endl;
  return 0;
}