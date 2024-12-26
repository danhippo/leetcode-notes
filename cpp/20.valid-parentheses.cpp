/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 == 1) return false;

        stack<char> stackParentheses;
        unordered_map<char, char> map;
        map.insert({'(',')'});
        map.insert({'{','}'});
        map.insert({'[',']'});

        for(int i = 0 ; i < s.size(); i++)
        {
            if(map.find(s[i]) != map.end())
                stackParentheses.push(map[s[i]]);
            else
            {
                if(stackParentheses.empty()) return false;

                int topChar = stackParentheses.top();
                stackParentheses.pop();
                if(topChar!=s[i])
                    return false;
            }
        }
        if(stackParentheses.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

