
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/**
 * Problem Origin: Leetcode
 * Problem Name: Unique Number of Occurrences
 * Problem No: 1207
 * Difficulty: Easy
 * Problem Link: https://leetcode.com/problems/unique-number-of-occurrences/description/
 * Problem Description: Given an array of integers arr, return true if the number of
 * occurrences of each value in the array is unique or false otherwise.
 * 
 * Approach: Hash Map + Hash Set
 *   1. Count the occurrences of each value using a hash map.
 *   2. Insert all those counts into a hash set (duplicates are discarded).
 *   3. If the set has the same size as the map, every count was unique.
 *      If it is smaller, at least two values shared a count.
 * 
 * Examples:
 *   1. Example 1:
 *      Input: arr = [1,2,2,1,1,3]
 *      Output: true
 *      Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the
 *      same number of occurrences.
 *   2. Example 2:
 *      Input: arr = [1,2]
 *      Output: false
 *   3. Example 3:
 *      Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 *      Output: true
 * 
 * Constraints:
 *   1 <= arr.length <= 1000
 *   -1000 <= arr[i] <= 1000
 * 
 * Time Complexity:  O(n) - one pass over arr, one pass over the map
 * Space Complexity: O(k) - k = number of distinct values (k <= n)
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      // Map: value -> number of times it appears in arr
        unordered_map<int,int> nums;

        for(auto num: arr) {
            nums[num]++;
        }

        // Set of occurrence counts; a set keeps only distinct counts
        unordered_set<int> freq;
        for(auto m: nums) {
            freq.insert(m.second); // m.second = count of value m.first
        }

        // Equal sizes means no two values shared the same count
        return freq.size() == nums.size();
    }
};