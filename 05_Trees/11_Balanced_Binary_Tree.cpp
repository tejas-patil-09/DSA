/*
Problem:
Determine whether a binary tree is height-balanced.

Input:
The root of a binary tree.

Output:
true if for every node the difference between the heights of
the left and right subtrees is at most 1; otherwise false.

Approach:
1. Brute:
   For every node, calculate left and right heights separately.
   This can take O(N^2) in the worst case.

2. Optimal:
   Use a height function that returns:
   - Actual height if the subtree is balanced.
   - -1 if the subtree is unbalanced.

   If a child returns -1, propagate -1 immediately.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
Use -1 as a signal that an unbalanced subtree was found,
so height and balance are checked in one traversal.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftH = height(root->left);
        if (leftH == -1)
            return -1;

        int rightH = height(root->right);
        if (rightH == -1)
            return -1;

        if (abs(leftH - rightH) > 1)
            return -1;

        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
