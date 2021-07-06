/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        if(k==0) return;
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums)+k);
        reverse(begin(nums)+k, end(nums));
    }
};
// @lc code=end

