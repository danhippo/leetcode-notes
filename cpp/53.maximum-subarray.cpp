/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;

        int cur_sum = nums[0];
        int sum_so_far = nums[0];
        int max_sum = nums[0];
        for(vector<int>::iterator it = nums.begin() + 1; it!=nums.end(); ++it)
        {
            cur_sum = sum_so_far + *it;
            sum_so_far = max(*it, cur_sum);
            max_sum = max(max_sum, sum_so_far);
        }
        return max_sum;

    }
};
// @lc code=end

