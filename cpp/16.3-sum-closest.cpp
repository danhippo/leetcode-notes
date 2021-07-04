/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = nums[0] + nums[1] + nums[2];
        int min = abs(sum - target);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n -2; i++)
        {
            int l = i+1;
            int r = n -1;
            while(l<r)
            {
                int cur = nums[i] + nums[l] + nums[r];
                int diff = abs(target - cur);
                if(diff<min)
                {
                    sum = cur;
                    min = diff;
                }
                if(cur<target) ++l;
                else if(cur>target) --r;
                else return target;
            }
        }
        return sum;
    }
};
// @lc code=end

