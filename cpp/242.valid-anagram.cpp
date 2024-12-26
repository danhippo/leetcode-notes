/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> rec_map;
        for(int i = 0; i< s.size(); i++)
        {
            if(rec_map.find(s[i]) != rec_map.end())
                rec_map[s[i]] += 1;
            else
                rec_map[s[i]] = 1;

            if(rec_map.find(t[i]) != rec_map.end())
                rec_map[t[i]] -= 1;
            else
                rec_map[t[i]] = -1;

        }

        for(unordered_map<char, int>::iterator it = rec_map.begin(); it != rec_map.end(); ++it)
        {
            if(it->second !=0)
                return false;
        }

        return true;
        
    }
};
// @lc code=end

