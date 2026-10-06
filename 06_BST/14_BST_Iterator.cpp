/*
Problem:
Implement an iterator over a Binary Search Tree that returns
the elements in ascending order.

Input:
Root of a BST.

Operations:
- next()    → returns the next smallest value.
- hasNext() → checks whether another value exists.

Approach:
Use a stack to store the path to the next smallest node.

pushLeft():
- Push the current node.
- Keep moving to the left.

next():
1. Pop the smallest available node.
2. If it has a right subtree, push the left path of that subtree.
3. Return the node's value.

TC:
- next(): Amortized O(1)
- hasNext(): O(1)

SC: O(H)

Key Insight:
The stack stores the iterator's current state and always keeps
the next smallest node available at the top.
==========================================================
*/

class BSTIterator {
private:
    stack<TreeNode*> leftStack;

    void pushLeft(TreeNode* root) {
        while (root) {
            leftStack.push(root);
            root = root->left;
        }
    }

public:

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = leftStack.top();
        leftStack.pop();

        if (node->right)
            pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !leftStack.empty();
    }
};