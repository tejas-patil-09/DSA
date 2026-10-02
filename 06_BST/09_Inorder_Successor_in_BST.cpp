/*
Problem:
Find the inorder successor of a given node in a BST.

The successor is the smallest value strictly greater
than the given node.

Input:
        5
       / \
      3   7
     / \ / \
    2  4 6  8

node = 5

Output:
6

Brute Force:
Perform inorder traversal and find the next value after
the given node.

Time Complexity: O(N)
Space Complexity: O(H)

Optimal Approach:
Use the BST property.

If root->val > node->val:
- root is a possible successor.
- Save it as candidate.
- Go left to search for a smaller valid candidate.

Otherwise:
- root cannot be the successor.
- Go right.

Time Complexity: O(H)
Space Complexity: O(1)

Key Insight:
Candidate + move toward a better candidate.
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root,
                                TreeNode* node) {
        TreeNode* ans = nullptr;

        while (root) {
            if (root->val > node->val) {
                ans = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return ans;
    }
};