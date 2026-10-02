/*
Problem:
Given the preorder traversal of a BST, construct the
original BST.

Input:
preorder = [8,5,1,7,10,12]

Output:
        8
       / \
      5   10
     / \    \
    1   7    12

Brute Force:
Insert every preorder value one by one into a BST.

Time Complexity: O(N^2) worst case
Space Complexity: O(N)

Optimal Approach:
Use preorder order along with a valid value range.

For every value:
- If it does not fit the current range, do not consume it.
- If it fits, create the node and increment the index.
- Recursively construct left and right subtrees.

Time Complexity: O(N)
Space Complexity: O(H)

Key Insight:
The index represents the next unused preorder value.
The range represents restrictions imposed by ancestors.
*/

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& i,
                    long long min, long long max) {
        if (i >= preorder.size())
            return nullptr;

        if (preorder[i] <= min || preorder[i] >= max)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = build(preorder, i, min, root->val);
        root->right = build(preorder, i, root->val, max);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;

        return build(preorder, i,
                     LLONG_MIN, LLONG_MAX);
    }
};