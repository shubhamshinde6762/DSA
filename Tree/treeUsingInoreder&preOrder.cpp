#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    map<int, int> mp;

    void create(vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd, int n)
    {
        if (preIndex >= n || inStart > inEnd)
            return NULL;

        // creating new Node of Data
        int element = preorder[preIndex++];
        TreeNode *root = new TreeNode(element);

        // Checking posn for right and left
        int pos = mp[element];

        // call for Left Part
        root->left = solve(preorder, inorder, preIndex, inStart, pos - 1, n);
        root->right = solve(preorder, inorder, preIndex, pos + 1, inEnd, n);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int preIndex = 0;
        int n = inEnd + 1;
        create(inorder);
        return solve(preorder, inorder, preIndex, inStart, inEnd, n);
    }
};