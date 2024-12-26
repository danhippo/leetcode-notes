/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> dst;
       if(!root) return dst;
       vector<int> leftPart = inorderTraversal(root->left);
       if(!leftPart.empty()) dst.insert(dst.end(), leftPart.begin(), leftPart.end());
       dst.push_back(root->val);
       vector<int> rightPart = inorderTraversal(root->right);
       if(!rightPart.empty()) dst.insert(dst.end(), rightPart.begin(), rightPart.end());
       return dst;
    }
};
// @lc code=end

