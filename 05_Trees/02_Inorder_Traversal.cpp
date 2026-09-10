/*
Problem:
Return the inorder traversal of a binary tree.

Input:
The root of a binary tree.

Output:
A vector containing the nodes in inorder.

Approach:
   Use recursion:
   - Traverse left subtree.
   - Visit root.
   - Traverse right subtree.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion, O(N) for the output.

Key Insight:
Inorder follows Left → Root → Right.
For a BST, inorder traversal gives sorted order.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
