/*
Problem:
Return the boundary of a binary tree in
anti-clockwise order.

Input:
        1
       / \
      2   3
     / \   \
    4   5   6

Output:
    [1, 2, 4, 5, 6, 3]

Approach:
1. Add root (if it is not a leaf).
2. Add left boundary, excluding leaves.
3. Add all leaves from left to right.
4. Add right boundary in reverse, excluding leaves.

TC: O(n)
SC: O(h), excluding output
==========================================================
*/

class Solution {
private:
    bool isLeaf(TreeNode* node) {
        return node &&
               node->left == nullptr &&
               node->right == nullptr;
    }

    void addLeftBoundary(TreeNode* root,
                         vector<int>& ans) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->val);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root,
                   vector<int>& ans) {
        if (root == nullptr)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root,
                          vector<int>& ans) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->val);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

public:
    vector<int> boundary(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        if (!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};