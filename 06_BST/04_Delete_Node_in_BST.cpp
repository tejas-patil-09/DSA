/*
Problem:
Delete a node with a given key from a Binary Search Tree
and return the root.

Input:
root = [5,3,6,2,4,null,7]
key = 3

Output:
[5,4,6,2,null,null,7]

Brute Force:
Find the node and restructure the tree manually using
parent pointers.

Time Complexity: O(H)
Space Complexity: O(1)

Optimal Approach:
There are three cases:

1. Node has no child:
   Return nullptr.

2. Node has one child:
   Return the existing child so it replaces the node.

3. Node has two children:
   Find the inorder successor (smallest node in the
   right subtree), copy its value into the current node,
   then delete the successor.

Time Complexity: O(H)
Space Complexity: O(H) due to recursion

Key Insight:
The recursive function returns the new root of the
current subtree. This is why we use:

root->left = deleteNode(...)
root->right = deleteNode(...)
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left)
                return root->right;

            if (!root->right)
                return root->left;

            TreeNode* successor = root->right;

            while (successor->left)
                successor = successor->left;

            root->val = successor->val;

            root->right = deleteNode(root->right,
                                     successor->val);
        }

        return root;
    }
};