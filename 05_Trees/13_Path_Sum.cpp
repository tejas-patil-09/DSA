/*
Problem:
Check if a root-to-leaf path has sum equal to targetSum.

Input:
    Tree: [5,4,8,11,null,13,4,7,2,null,null,null,1]
    targetSum = 22

Output:
    true

Approach:
1. If root is nullptr, return false.
2. Subtract root's value from targetSum.
3. At a leaf, check if the remaining sum is zero.
4. Recursively check left OR right subtree.

TC: O(n)
SC: O(h), recursion stack
==========================================================
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        targetSum -= root->val;

        if (root->left == nullptr &&
            root->right == nullptr) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};