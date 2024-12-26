/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dst;
        if(nums1.size() == 0 || nums2.size()==0)
            return dst;

        unordered_map<int, int> rec_map;
        for(vector<int>::iterator it = nums1.begin(); it != nums1.end();++it)
        {
            if(rec_map.find(*it)!=rec_map.end())
                rec_map[*it] += 1;
            else
                rec_map[*it] = 1;
        }

        for(vector<int>::iterator it = nums2.begin(); it != nums2.end();++it)
        {
            if(rec_map.find(*it)!=rec_map.end() && rec_map[*it] != 0)
            {
                rec_map[*it] -= 1;
                dst.push_back(*it);
            }
        }
        return dst;
    }
};
// @lc code=end

