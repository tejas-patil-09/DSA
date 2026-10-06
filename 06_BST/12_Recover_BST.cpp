/*
Problem:
Two nodes of a Binary Search Tree have been swapped by mistake.
Restore the BST without changing its structure.

Input:
Root of a Binary Search Tree.

Output:
Restore the BST by swapping the values of the two incorrect nodes.

Approach:
Inorder traversal of a valid BST gives sorted order.

While performing inorder traversal:
- If prev->val > root->val, a BST violation is found.
- At the first violation, store prev as the first incorrect node.
- At every violation, store root as the second incorrect node.
- After traversal, swap the values of first and second.

TC: O(N)
SC: O(H)

Key Insight:
A valid BST always has sorted inorder traversal.
The swapped nodes can therefore be detected through inorder violations.
==========================================================
*/

class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (first && second)
            swap(first->val, second->val);
    }
};