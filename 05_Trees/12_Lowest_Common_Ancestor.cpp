/*
Problem:
Find the lowest common ancestor of two nodes p and q
in a binary tree.

Input:
        3
       / \
      5   1
     / \
    6   2

    p = 5, q = 1

Output:
    3

Approach:
1. If root is nullptr, return nullptr.
2. If root is p or q, return root.
3. Recursively search left and right.
4. If both return non-null, root is the LCA.
5. Otherwise, return the non-null result.

TC: O(n)
SC: O(h), recursion stack
==========================================================
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(
            root->left, p, q
        );

        TreeNode* right = lowestCommonAncestor(
            root->right, p, q
        );

        if (left && right)
            return root;

        return left ? left : right;
    }
};