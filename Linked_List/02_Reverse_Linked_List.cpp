/*
Problem:
Reverse a singly linked list.

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
5 -> 4 -> 3 -> 2 -> 1

Approach:
1. Brute:
   Store the linked list values in an array/vector,
   reverse the values, and update the linked list.

2. Optimal:
   Reverse the links in-place using three pointers:
   prev, head, and nextHead.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Store the next node before changing head->next,
then reverse the current link and move forward.
==========================================================
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextHead = head->next;

            head->next = prev;
            prev = head;
            head = nextHead;
        }

        return prev;
    }
};