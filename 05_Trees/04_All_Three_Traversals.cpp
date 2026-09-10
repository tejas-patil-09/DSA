/*
Problem:
Return the preorder, inorder, and postorder traversals
of a binary tree.

Input:
The root of a binary tree.

Output:
Three vectors containing preorder, inorder, and postorder.

Approach:
   Use the three recursive traversal functions:
   - Preorder: Root → Left → Right
   - Inorder: Left → Root → Right
   - Postorder: Left → Right → Root

Time Complexity:
O(N) asymptotically for each traversal; three traversals are
still O(N).

Space Complexity:
O(H) auxiliary recursion space, O(N) for the outputs.

Key Insight:
The traversal order changes only by the position at which
the current node is processed.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    void postorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<vector<int>> allTraversals(TreeNode* root) {
        vector<int> pre, in, post;

        preorder(root, pre);
        inorder(root, in);
        postorder(root, post);

        return {pre, in, post};
    }
};
