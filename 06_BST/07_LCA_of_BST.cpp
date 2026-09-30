/*
Problem:
Find the lowest common ancestor of two nodes in a BST.

Input:
        6
       / \
      2   8
     / \ / \
    0  4 7  9

p = 2
q = 8

Output:
6

Brute Force:
Use general binary-tree LCA logic by exploring both
subtrees.

Time Complexity: O(N)
Space Complexity: O(H)

Optimal Approach:
Use the BST property.

- If both p and q are smaller than root -> go left.
- If both p and q are greater than root -> go right.
- Otherwise, current root is the LCA.

Time Complexity: O(H)
Space Complexity: O(H) due to recursion

Key Insight:
The first node where p and q split into different
directions is their LCA.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                    TreeNode* p,
                                    TreeNode* q) {
        if (root->val < p->val &&
            root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        if (root->val > p->val &&
            root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};