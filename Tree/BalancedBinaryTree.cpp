#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    int height(TreeNode* root)
    {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int left = height(root->left);
        int right = height(root->right);

        int diff = abs(left - right);

        bool current = (diff <= 1);

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        return current && l && r;
    }
};