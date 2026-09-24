/*
Problem:
Return level-order traversal with alternating directions.

Input:
        3
       / \
      9   20
         /  \
        15   7

Output:
    [[3], [20,9], [15,7]]

Approach:
1. Use a queue for level-order traversal.
2. Process one level at a time.
3. Place values at normal or reversed indices.
4. Toggle direction after each level.

TC: O(n)
SC: O(n)
==========================================================
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();

            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight
                          ? i
                          : size - 1 - i;

                level[index] = node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};