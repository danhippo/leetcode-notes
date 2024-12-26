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
        int left = 0; int right = nums.size() -1;
        while(left < right)
        {
            int mid = (right + left)/2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else 
                right = mid;
        }
        return nums[left];
    }
};
// @lc code=end

