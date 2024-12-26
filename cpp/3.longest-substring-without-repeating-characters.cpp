/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<iostream>
#include<unordered_set>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> subString;
        int maxNum = 0;
        int slow =0;
        for(int fast = 0; fast < s.size(); fast++)
        {
            while(subString.find(s[fast])!=subString.end())
            {
                subString.erase(s[slow]);
                slow++;
            }
            
            subString.insert(s[fast]);
            maxNum = max(int(subString.size()), maxNum);
        }

        return maxNum;
    }
};
// @lc code=end

