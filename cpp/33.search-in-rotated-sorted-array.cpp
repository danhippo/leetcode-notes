/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_idx = 0;
        int right_idx = nums.size() - 1;
        int mid_idx;
        while(left_idx<=right_idx)
        {
            mid_idx = left_idx + ((right_idx - left_idx) >> 1);
            if(nums[mid_idx] == target) return mid_idx;
            if(nums[mid_idx] > nums[right_idx])
            {
                if(target < nums[mid_idx] && target >= nums[left_idx]) right_idx = mid_idx -1;
                else left_idx = mid_idx + 1;
            }
            else
            {
                if(target > nums[mid_idx] && target <= nums[right_idx]) left_idx = mid_idx +1;
                else right_idx = mid_idx - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

