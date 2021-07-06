/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<0) return n;
        int ans=0;

        int p1=0;
        while(p1<n)
        {
            nums[ans++] = nums[p1];
            int p2 = p1+1;
            while(p2<n && nums[p2]==nums[p2-1]) ++p2;
            p1=p2;
        }
        return ans;
    }
};
// @lc code=end

