/*
Problem:
Invert a binary tree by swapping the left and right children
of every node.

Input:
The root of a binary tree.

Output:
The root of the inverted tree.

Approach:
   - Swap root->left and root->right.
   - Invert the left subtree.
   - Invert the right subtree.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
The tree can be modified in-place because TreeNode* points to
the actual nodes. The returned pointer does not need to be stored
inside recursive calls.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
