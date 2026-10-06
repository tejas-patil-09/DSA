/*
Problem:
Given the root of a Binary Search Tree and a target value,
determine whether there exist two distinct nodes whose values
add up to the target.

Input:
Root of a BST and target integer k.

Output:
true if two distinct nodes sum to k, otherwise false.

Approach:
Use two stacks to simulate two pointers on the sorted inorder
sequence without storing the complete sequence.

- Stack 1 performs normal inorder traversal → smallest values.
- Stack 2 performs reverse inorder traversal → largest values.
- Compare the two values like the two-pointer technique.

If sum == target → return true.
If sum < target → move the smaller iterator forward.
If sum > target → move the larger iterator backward.

TC: O(N)
SC: O(H)

Key Insight:
Two BST iterators can simulate two pointers on the sorted inorder
sequence while using only O(H) extra space.
==========================================================
*/

class Solution {
public:

    void pushLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {

        if (!root)
            return false;

        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;

        pushLeft(root, leftStack);
        pushRight(root, rightStack);

        while (!leftStack.empty() && !rightStack.empty()) {

            TreeNode* leftNode = leftStack.top();
            TreeNode* rightNode = rightStack.top();

            // Same node means no two distinct nodes remain.
            if (leftNode == rightNode)
                break;

            int sum = leftNode->val + rightNode->val;

            if (sum == k)
                return true;

            if (sum < k) {
                leftStack.pop();

                if (leftNode->right)
                    pushLeft(leftNode->right, leftStack);
            }
            else {
                rightStack.pop();

                if (rightNode->left)
                    pushRight(rightNode->left, rightStack);
            }
        }

        return false;
    }
};