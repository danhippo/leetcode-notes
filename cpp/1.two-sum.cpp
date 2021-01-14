/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();

        vector<int>::iterator it;
        map<int,int> numMap;
        int index = 0;
        for(it = begin; it != end; it++, index++)
        {
            int res = target - *it;
            map<int,int>::iterator pair = numMap.find(res);
            if(pair!=numMap.end())
            {
                vector<int> dst;
                dst.push_back(index);
                dst.push_back(pair->second);
                return dst;
            }
            numMap[*it]=index;
        }

        throw invalid_argument("no 2 sum solution exist.");
    }
};
// @lc code=end

