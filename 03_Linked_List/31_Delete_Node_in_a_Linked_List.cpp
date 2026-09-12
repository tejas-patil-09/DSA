/*
Problem:
Delete a given node from a singly linked list.
The previous node is not given.
The given node is guaranteed not to be the tail.

Input:
4 -> 5 -> 1 -> 9
Given node = 5

Output:
4 -> 1 -> 9

Approach:

1. Normally, to delete a node from a singly linked list,
   we need the previous node.

2. But here, the previous node is not provided.

3. Copy the value of the next node into the current node.

4. Skip the next node by changing the current node's next pointer.

Key Insight:
We don't actually remove the given node.
We make it become the next node, then remove the next node.

Time Complexity:
O(1)

Space Complexity:
O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
