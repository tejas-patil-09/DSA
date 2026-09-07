/*
Problem:
Rotate a linked list to the right by k places.

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
4 -> 5 -> 1 -> 2 -> 3

Brute:
Rotate the list one position at a time, k times.

Optimal:
Find the length of the list and connect the tail to the
head to form a circular list. Then break the circle at
the correct position.

TC: O(n)
SC: O(1)

Key Insight:
Only k % n rotations are needed because rotating n times
returns the list to its original state.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int length = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k %= length;

        if (k == 0)
            return head;

        tail->next = head;

        int steps = length - k;

        ListNode* newTail = tail;

        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};