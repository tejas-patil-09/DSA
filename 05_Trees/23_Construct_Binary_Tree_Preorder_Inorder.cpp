/*
Problem:
Construct a binary tree using its preorder and
inorder traversal arrays.

Input:
Preorder and inorder arrays of a binary tree
with unique values.

Output:
Root of the constructed binary tree.

Approach:
1. Preorder gives the root first.
2. Find that root in inorder.
3. Values left of it form the left subtree;
   values right of it form the right subtree.
4. Recursively build both subtrees.

TC: O(N)
SC: O(N)

Key Insight:
Preorder identifies the root; inorder separates
the left and right subtrees.
==========================================================
*/

class Solution {
    unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    int inLeft, int inRight) {
        if (inLeft > inRight)
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inMap[rootVal];

        root->left = build(preorder, inLeft, mid - 1);
        root->right = build(preorder, mid + 1, inRight);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {
        preIndex = 0;
        inMap.clear();

        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};