/*
Problem:
Return the nodes visible when viewing the tree
from the left side.

Input:
        1
       / \
      2   3
       \   \
        5   6

Output:
    [1, 2, 5]

Approach:
1. Perform level-order traversal.
2. Process one level at a time.
3. Store the first node of every level.

TC: O(n)
SC: O(n)
==========================================================
*/

class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == 0)
                    ans.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};