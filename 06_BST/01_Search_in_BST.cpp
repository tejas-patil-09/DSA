/*
Problem:
Given the root of a Binary Search Tree and a value,
return the node containing that value.
If the value is not present, return nullptr.

Input:
root = [4,2,7,1,3]
val = 2

Output:
[2,1,3]

Brute Force:
Perform any tree traversal and check every node.

Time Complexity: O(N)
Space Complexity: O(H)

Optimal Approach:
Use the BST property:
- If val < root->val, search left.
- If val > root->val, search right.
- Otherwise, the current node is the answer.

Time Complexity: O(H)
Space Complexity: O(H) due to recursion

Key Insight:
A BST allows us to eliminate one entire subtree at every step.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;

        if (val < root->val)
            return searchBST(root->left, val);

        if (val > root->val)
            return searchBST(root->right, val);

        return root;
    }
};