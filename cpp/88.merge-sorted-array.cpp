/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while(i<m || j<n)
        {
            if(i>=m)
            {
                result.push_back(nums2[j++]);
                continue;
            }

            if(j>=n)
            {
                result.push_back(nums1[i++]);
                continue;
            }

            if(!nums2.empty() && nums1[i]>nums2[j])
                result.push_back(nums2[j++]);
            else
                result.push_back(nums1[i++]);
        }

        for(int cnt = 0; cnt<nums1.size();cnt++)
            nums1[cnt] = result[cnt];
    }
};
// @lc code=end

