/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int head = 0;
        int i = 0;
        int temp;
        while(i<n-1)
        {
            int j = i+1;
            while(nums[i]==0 && j<n-1 && nums[j]==0) ++j;
            if(j==n-1 && nums[j]==0) return;
            if(nums[i]==0)
            {
                temp = nums[head];
                nums[head] = nums[j];
                nums[j] = temp;
            }
            i=j;
            ++head;
        }
    }
};
// @lc code=end

