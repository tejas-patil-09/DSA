/*
Problem:
Return the nodes visible when the tree is viewed
from the bottom.

Input:
Root of a binary tree.

Output:
Vector containing bottom-view nodes from left to right.

Approach:
BFS with horizontal distance (column).
Update the value at each column whenever a node
is encountered.

TC: O(N log N)
SC: O(N)

Key Insight:
The last BFS-visited node at a column becomes its
bottom-view node. Left-to-right BFS handles common
same-depth ties.
==========================================================
*/

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> bottom;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            bottom[col] = node->val;

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto it : bottom)
            ans.push_back(it.second);

        return ans;
    }
};