/*
Problem:
Return the level order traversal of a binary tree.

Input:
The root of a binary tree.

Output:
A vector of vectors where each inner vector contains one level.

Approach:
   Use a queue for BFS.
   At the start of each level, store q.size() to know how many
   nodes belong to the current level.
   Process exactly those nodes and push their children for
   the next level.

Time Complexity:
O(N)

Space Complexity:
O(N)

Key Insight:
Queue gives FIFO order, while size separates the current level
from the next level.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
