/*
Problem:
Determine whether a binary tree is symmetric around its center.

Input:
The root of a binary tree.

Output:
true if the tree is symmetric; otherwise false.

Approach:
1. Brute:
   Traverse/store both sides and compare after reversing one side.

2. Optimal:
   Recursively compare two nodes as mirror images:
   - Both null → true.
   - Only one null → false.
   - Values differ → false.
   - left->left with right->right.
   - left->right with right->left.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
Same Tree compares same positions.
Symmetric Tree compares mirror positions.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool mirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return mirror(root->left, root->right);
    }
};
