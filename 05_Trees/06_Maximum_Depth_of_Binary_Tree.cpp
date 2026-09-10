/*
Problem:
Find the maximum depth of a binary tree.

Input:
The root of a binary tree.

Output:
The number of nodes on the longest root-to-leaf path.

Approach:
   Recursively calculate the height of the left and right
   subtrees, then return:
   1 + max(leftHeight, rightHeight)

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
depth(root) = 1 + max(depth(left), depth(right)).
A null tree has depth 0.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};
