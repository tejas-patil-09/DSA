/*
Problem:
Return the average value of nodes at each level.

Input:
        3
       / \
      9   20
         /  \
        15   7

Output:
    [3.00000, 14.50000, 11.00000]

Approach:
1. Use a queue for level-order traversal.
2. Process one level at a time.
3. Calculate the sum of values in that level.
4. Divide by the number of nodes in the level.

TC: O(n)
SC: O(n)
==========================================================
*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(sum / size);
        }

        return ans;
    }
};