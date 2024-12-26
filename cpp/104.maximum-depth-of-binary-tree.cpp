/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // DFS solution
        /* 
        if(root==nullptr) return 0;
        int leftLength = maxDepth(root->left);
        int rightLength = maxDepth(root->right);
        return max(leftLength, rightLength) +1;// + 1 is current level
        */
        // BFS solution
        if(root==nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int maxDepth = 0;
        while(!q.empty())
        {
            pair<TreeNode*, int> curNode = q.front();
            q.pop();
            maxDepth = max(maxDepth, curNode.second);
            if(curNode.first->left) q.push(make_pair(curNode.first->left, curNode.second+1));
            if(curNode.first->right) q.push(make_pair(curNode.first->right, curNode.second+1));
        }
        return maxDepth;
    }
};
// @lc code=end

