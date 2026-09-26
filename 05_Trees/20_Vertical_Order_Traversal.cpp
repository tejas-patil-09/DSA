/*
Problem:
Group nodes by vertical column, from left to right.

Input:
        1
       / \
      2   3
     /     \
    4       5

Output:
    [[4], [2], [1], [3], [5]]

Approach:
1. Use BFS with each node's horizontal column.
2. Left child gets column - 1.
3. Right child gets column + 1.
4. Store values in an ordered map by column.
5. Return columns from left to right.

TC: O(n log n)
SC: O(n)
==========================================================
*/

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            columns[col].push_back(node->val);

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto& [col, values] : columns)
            ans.push_back(values);

        return ans;
    }
};