/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){return a[0]<b[0];}
            );
        int n = intervals.size();
        vector<vector<int>> result;
        for(int i = 0; i < n; ++i)
        {
            vector<int> cur = intervals[i];
            if(result.empty() || result.back()[1]<cur[0])
                result.push_back(cur);
            else
                result.back()[1] = max(cur[1], result.back()[1]);
        }
        return result;
    }
};
// @lc code=end

