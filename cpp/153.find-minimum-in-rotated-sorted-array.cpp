/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left_idx = 0;
        int right_idx = nums.size() - 1;
        int mid_idx;
        while(nums[left_idx]!=nums[right_idx])
        {
            mid_idx = left_idx + ((right_idx - left_idx) >> 1);
            if(nums[mid_idx]<nums[right_idx])
                right_idx = mid_idx;
            else
                left_idx = mid_idx + 1;
        }
        return nums[left_idx];
    }
};
// @lc code=end

