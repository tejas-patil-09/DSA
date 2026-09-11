/*
Problem:
Find the diameter of a binary tree.
The diameter is the longest path between any two nodes,
measured in number of edges.

Input:
The root of a binary tree.

Output:
The diameter of the tree.

Approach:
1. Brute:
   For every node, calculate left and right subtree heights
   separately and take the maximum diameter.
   This can take O(N^2) in the worst case.

2. Optimal:
   Calculate height and diameter together in one traversal.
   At every node:
   diameter through node = leftHeight + rightHeight.
   Update the maximum diameter and return the height.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
The longest diameter does not necessarily pass through the root.
Check the diameter at every node while calculating heights.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int height(TreeNode* root, int& diameter) {
        if (!root)
            return 0;

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};
