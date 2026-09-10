/*
Problem:
Return the postorder traversal of a binary tree.

Input:
The root of a binary tree.

Output:
A vector containing the nodes in postorder.

Approach:
   Use recursion:
   - Traverse left subtree.
   - Traverse right subtree.
   - Visit root.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion, O(N) for the output.

Key Insight:
Postorder follows Left → Right → Root.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void postorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
