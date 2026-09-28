/*
Problem:
Insert a new value into a Binary Search Tree and return
the root of the resulting tree.

Input:
root = [4,2,7,1,3]
val = 5

Output:
[4,2,7,1,3,5]

Brute Force:
Not applicable in the usual sense because insertion must
preserve the BST property.

Optimal Approach:
Start from the root and follow the BST property:
- Smaller value -> left
- Larger value -> right

Continue until a nullptr is found, then attach the new node.

Time Complexity: O(H)
Space Complexity: O(1)

Key Insight:
Nodes do not shift like elements in an array.
The new node is simply attached at the first available
nullptr position along the correct BST path.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode* node = root;
        TreeNode* prev = nullptr;

        while (node) {
            if (node->val < val) {
                prev = node;
                node = node->right;
            }
            else {
                prev = node;
                node = node->left;
            }
        }

        if (val < prev->val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);

        return root;
    }
};