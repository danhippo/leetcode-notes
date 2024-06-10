/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> Result(nums.size(),1);
        int product = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            product = product * nums[i - 1];
            Result[i] *= product;
        }

        product = 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            product = product * nums[i + 1];
            Result[i] *= product;
        }
        return Result;

    }
};
// @lc code=end

