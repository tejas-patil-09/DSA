/*
Problem:
Return all root-to-leaf paths as strings.

Input:
        1
       / \
      2   3
       \
        5

Output:
    ["1->2->5", "1->3"]

Approach:
1. Add current node to path.
2. If leaf, store the completed path.
3. Otherwise, recurse left and right.
4. Pass path by value to keep branches independent.

TC: O(n * h) including path construction
SC: O(h) recursion, excluding output
==========================================================
*/

class Solution {
public:
    void solve(TreeNode* root,
               string path,
               vector<string>& ans) {
        if (root == nullptr)
            return;

        if (!path.empty())
            path += "->";

        path += to_string(root->val);

        if (root->left == nullptr &&
            root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        solve(root, "", ans);

        return ans;
    }
};