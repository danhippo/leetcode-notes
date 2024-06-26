/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while(right > left)
        {
            result = max(result, min(height[left], height[right]) * (right - left));

            if(height[left] > height[right])
                right -= 1;
            else 
                left += 1;
        }
        return result;
    }
};
// @lc code=end

