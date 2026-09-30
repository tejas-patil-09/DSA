/*
Problem:
Given a BST and an integer k, return the kth smallest
value.

Input:
root = [3,1,4,null,2]
k = 1

Output:
1

Brute Force:
Perform inorder traversal, store all values in a vector,
then return the kth element.

Time Complexity: O(N)
Space Complexity: O(N)

Optimal Approach:
Inorder traversal of a BST produces values in sorted order.

Keep a counter while performing inorder traversal.
When the counter reaches k, return that value.

Time Complexity: O(N) worst case
Space Complexity: O(H)

Key Insight:
BST inorder traversal = sorted order.

Recursive pattern:
left -> current -> right
*/

class Solution {
public:
    int kth(TreeNode* root, int k, int& i) {
        if (!root)
            return -1;

        int left = kth(root->left, k, i);

        if (left != -1)
            return left;

        i++;

        if (k == i)
            return root->val;

        int right = kth(root->right, k, i);

        if (right != -1)
            return right;

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return kth(root, k, i);
    }
};