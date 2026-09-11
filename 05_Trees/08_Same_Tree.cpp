/*
Problem:
Determine whether two binary trees are identical.

Input:
The roots of two binary trees.

Output:
true if both trees have the same structure and node values;
otherwise false.

Approach:
1. Brute:
   Traverse both trees separately and store their traversals,
   then compare them.

2. Optimal:
   Compare corresponding nodes recursively:
   - Both null → true.
   - Only one null → false.
   - Different values → false.
   - Otherwise compare left and right subtrees.

Time Complexity:
O(N)

Space Complexity:
O(H) auxiliary space for recursion.

Key Insight:
Same Tree means comparing the same positions in both trees.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
