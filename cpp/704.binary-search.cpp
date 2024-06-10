/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        if(target>nums[right] || target < nums[left])
            return -1;

        while(left < right)
        {
            mid = left + ((right - left) >> 1);
            if(target > nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        if(nums[left] != target)
            return -1;
        else
            return left;
    }
};
// @lc code=end

