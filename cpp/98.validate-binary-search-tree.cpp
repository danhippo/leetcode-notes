/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }

private:
    bool isValid(TreeNode* root, long long minVal, long long maxVal)
    {
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
};
// @lc code=end

