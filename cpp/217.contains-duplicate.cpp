/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniq;
        for(auto it = nums.begin(); it != nums.end(); ++it)
            if(!uniq.insert(*it).second) return true;
        return false;
    }
};
// @lc code=end

