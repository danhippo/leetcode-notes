/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();

        vector<int>::iterator it;
        int cnt = 0;
        for(it = begin; it!=end; it++, cnt++) {
            if(target<=*it)
            {
                return cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end

