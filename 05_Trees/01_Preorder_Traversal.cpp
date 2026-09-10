/*
Problem:
Return the preorder traversal of a binary tree.

Input:
The root of a binary tree.

Output:
A vector containing the nodes in preorder.

Approach:
   Use recursion:
   - Visit root.
   - Traverse left subtree.
   - Traverse right subtree.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion, O(N) for the output.

Key Insight:
Preorder follows Root → Left → Right.
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

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
