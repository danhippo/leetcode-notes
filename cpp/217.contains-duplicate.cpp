/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniq;
        for(int num : nums)
            if(!uniq.insert(num).second) return true;
        return false;
    }
};
// @lc code=end

