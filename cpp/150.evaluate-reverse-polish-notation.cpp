/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s1;
        unordered_set<string> opSet = {"+", "-", "*", "/"};
        for(int i = 0 ;i<tokens.size(); i++)
        {
            if(opSet.find(tokens[i]) != opSet.end())
            {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                if(tokens[i] == "+")
                    s1.push(a+b);
                else if(tokens[i] == "-")
                    s1.push(a-b);
                else if(tokens[i] == "*")
                    s1.push(a*b);
                else if(tokens[i] == "/")
                    s1.push(a/b);
            }
            else
                s1.push(stoi(tokens[i]));
        }
        return s1.top();
    }
};
// @lc code=end

