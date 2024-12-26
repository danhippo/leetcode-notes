/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> dst(temperatures.size());
        stack<int> s1;
        stack<int> s2;
        for(int i = 0;i < temperatures.size(); i++)
        {
            while(!s1.empty() && s1.top() < temperatures[i])
            {
                dst[s2.top()] = i - s2.top();
                s1.pop();
                s2.pop();
            }

            s1.push(temperatures[i]);
            s2.push(i);
        }

        while(!s1.empty())
        {
            dst[s2.top()] = 0;
            s1.pop();
            s2.pop();
        }
        return dst;
    }
};
// @lc code=end

