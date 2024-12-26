/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int min_value = result;
        int max_value = result;
        int cur;
        for(int i = 1; i < nums.size(); i++)
        {
            cur = nums[i];
            if(cur < 0)
            {
                int temp = max_value;
                max_value = min_value;
                min_value = temp;
            }
            min_value = min(min_value*cur, cur);
            max_value = max(max_value*cur, cur);
            result = max(max_value, result);
        }
        return result;
    }
};
// @lc code=end

