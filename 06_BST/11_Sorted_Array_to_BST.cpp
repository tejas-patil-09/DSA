/*
Problem:
Given a sorted array, construct a height-balanced BST.

Input:
nums = [-10,-3,0,5,9]

Output:
[0,-3,9,-10,null,5]

Brute Force:
Repeatedly insert array elements into a BST.

Time Complexity: O(N log N) for a balanced result
Space Complexity: O(N)

Optimal Approach:
Use divide and conquer.

- Choose the middle element as root.
- Recursively construct the left subtree from the
  left half.
- Recursively construct the right subtree from the
  right half.

Use the upper middle:
mid = (low + high + 1) / 2

This produces:
        0
       / \
     -3   9
     /    /
   -10   5

Time Complexity: O(N)
Space Complexity: O(log N) recursion stack

Key Insight:
A sorted array can be converted into a balanced BST by
repeatedly choosing a middle element as the root.
*/

class Solution {
public:
    TreeNode* sorted(vector<int>& nums, int low, int high) {
        if (low > high)
            return nullptr;

        int mid = (low + high + 1) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sorted(nums, low, mid - 1);
        root->right = sorted(nums, mid + 1, high);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums, 0, nums.size() - 1);
    }
};