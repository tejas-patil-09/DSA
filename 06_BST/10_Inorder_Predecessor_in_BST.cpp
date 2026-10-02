/*
Problem:
Find the inorder predecessor of a given node in a BST.

The predecessor is the largest value strictly smaller
than the given node.

Input:
        5
       / \
      3   7
     / \ / \
    2  4 6  8

node = 6

Output:
5

Brute Force:
Perform inorder traversal and find the value immediately
before the given node.

Time Complexity: O(N)
Space Complexity: O(H)

Optimal Approach:
Use the BST property.

If root->val < node->val:
- root is a possible predecessor.
- Save it as candidate.
- Go right to search for a larger valid candidate.

Otherwise:
- root cannot be the predecessor.
- Go left.

Time Complexity: O(H)
Space Complexity: O(1)

Key Insight:
Predecessor is the mirror pattern of successor.

Successor:
greater -> candidate -> left

Predecessor:
smaller -> candidate -> right
*/

class Solution {
public:
    Node* inorderPredecessor(Node* root, Node* node) {
        Node* ans = nullptr;

        while (root) {
            if (root->data < node->data) {
                ans = root;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return ans;
    }
};