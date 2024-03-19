// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


// class Solution {

//     void create(map<int,int> &mp, vector<int>&in)
//     {
//         for (int i = 0; i < in.size(); i++)
//             mp[in[i]] = i;
//     }

//     TreeNode* solve(vector<int>& inorder, vector<int>& postorder, map<int,int>& mp, int &postIndex, int inStart, int inEnd)
//     {
//         if (postIndex < 0 || inStart > inEnd)
//             return NULL;

//         // create NOde 
//         int element = postorder[postIndex--];
//         TreeNode* root = new TreeNode(element);

//         // Find Position
//         int pos = mp[element];

//         // recurssive call for right
//         root->right = solve(inorder, postorder, mp, postIndex, pos + 1, inEnd);
//         root->left = solve(inorder, postorder, mp, postIndex, inStart, pos - 1);

//         return root;
//     }

// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         map<int, int> mp;
//         create(mp, inorder);
//         int postIndex = postorder.size() - 1;
//         return solve(inorder, postorder, mp ,postIndex, 0, postorder.size() - 1);
//     }
// };

// int main();