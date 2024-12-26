/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left, right, remain;
        vector<vector<int>> dst;
        for(int anchor = 0; anchor< nums.size() - 2; anchor++)
        {
            if(nums[anchor] > 0) break;
            if(anchor > 0 && nums[anchor] == nums[anchor - 1]) continue;
            remain = 0 - nums[anchor];
            left = anchor + 1;
            right = nums.size() - 1;
            while(left<right)
            {
                if(nums[left]+nums[right]<remain)
                    ++left;
                else if(nums[left]+nums[right]>remain)
                    --right;
                else
                {
                    dst.push_back({nums[anchor], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left < right && nums[left-1] == nums[left]) ++left;
                    while(left < right && nums[right+1] == nums[right]) --right;
                }
            }
        }
        return dst;
    }
};
// @lc code=end

