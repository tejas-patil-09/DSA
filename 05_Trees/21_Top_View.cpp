/*
Problem:
Return the nodes visible when the tree is viewed
from the top.

Input:
Root of a binary tree.

Output:
Vector containing top-view nodes from left to right.

Approach:
BFS with horizontal distance (column).
Store only the first node encountered at each column.

TC: O(N log N)
SC: O(N)

Key Insight:
BFS visits shallower nodes first, so the first node
at each column belongs to the top view.
==========================================================
*/

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> top;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            if (top.find(col) == top.end())
                top[col] = node->val;

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto it : top)
            ans.push_back(it.second);

        return ans;
    }
};