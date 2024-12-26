/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> q;
        unordered_map<int, int> map;
        vector<int> dst;
        for(int i = 0; i < nums2.size();i++)
        {
            while(!q.empty()&&q.top()<nums2[i])
            {
                map.insert({q.top(),nums2[i]});
                q.pop();
            }

            q.push(nums2[i]);
        }
        
        while(!q.empty())
        {
            map.insert({q.top(),-1});
            q.pop();
        }

        for(int i = 0; i< nums1.size();i++)
        {
            dst.push_back(map[nums1[i]]);
        }

        return dst;
    }
};
// @lc code=end

