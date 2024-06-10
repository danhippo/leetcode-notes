/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <iostream>
#include <vector>
using namespace vector;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int temp_max = nums[0];
        int sum_so_far = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            temp_max = max(nums[i], temp_max + nums[i]);
            sum_so_far = max(sum_so_far, temp_max);
        }
        return sum_so_far;
    }
};
// @lc code=end

