/*
Problem:
Return the middle node of a singly linked list.
If there are two middle nodes, return the second one.

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
3

Approach:
1. Brute:
   Traverse once to count the number of nodes,
   then traverse again to reach the middle.

2. Optimal:
   Use slow and fast pointers.
   Slow moves one step while fast moves two steps.
   When fast reaches the end, slow is at the middle.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Fast moves twice as fast as slow, so when fast
covers the list, slow has covered half of it.
==========================================================
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};