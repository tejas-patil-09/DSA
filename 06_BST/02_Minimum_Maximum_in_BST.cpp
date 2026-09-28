/*
Problem:
Find the minimum and maximum value in a Binary Search Tree.

Input:
        4
       / \
      2   7
     / \
    1   3

Output:
Minimum = 1
Maximum = 7

Brute Force:
Traverse the entire tree and keep track of the smallest
and largest values.

Time Complexity: O(N)
Space Complexity: O(H)

Optimal Approach:
In a BST:
- Minimum value is the leftmost node.
- Maximum value is the rightmost node.

Time Complexity: O(H)
Space Complexity: O(1)

Key Insight:
Keep moving left to find minimum and right to find maximum.
*/

class Solution {
public:
    int findMax(Node* root) {
        if (!root)
            return -1;

        while (root->right)
            root = root->right;

        return root->data;
    }

    int findMin(Node* root) {
        if (!root)
            return -1;

        while (root->left)
            root = root->left;

        return root->data;
    }
};