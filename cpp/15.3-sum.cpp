/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i=0; i<n; ++i)
        {
            if(i && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int t = 0 - nums[i];
                if(t < nums[j]+nums[k]) --k;
                else if(t > nums[j]+nums[k]) ++j;
                else{
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) ++j;
                    while(j<k && nums[k]==nums[k-1]) --k;
                    ++j;
                    --k;
                }
            }
        }
        return result;
    }
};
// @lc code=end

