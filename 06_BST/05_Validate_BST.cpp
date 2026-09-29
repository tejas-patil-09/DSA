/*
Problem:
Determine whether a binary tree is a valid Binary Search
Tree.

Input:
        5
       / \
      3   8
     / \
    2   6

Output:
false

Brute Force:
For every node, check its left and right subtree values.

Time Complexity: O(N^2) in the worst case
Space Complexity: O(H)

Optimal Approach:
Maintain the valid range for every node.

Initially:
(-infinity, +infinity)

For the left subtree:
(min, root->val)

For the right subtree:
(root->val, max)

Use long long for the boundaries so that INT_MIN and
INT_MAX can safely be node values.

Time Complexity: O(N)
Space Complexity: O(H)

Key Insight:
A node must satisfy restrictions imposed by ALL of its
ancestors, not just its immediate parent.
*/

class Solution {
public:
    bool isValid(TreeNode* root, long long min,
                 long long max) {
        if (!root)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return isValid(root->left, min, root->val) &&
               isValid(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};