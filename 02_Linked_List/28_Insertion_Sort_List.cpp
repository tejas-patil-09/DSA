/*
Problem:
Sort a singly linked list using insertion sort.

Input:
4 -> 2 -> 1 -> 3

Output:
1 -> 2 -> 3 -> 4

Approach:
Maintain two parts:

1. Sorted portion
2. Unsorted portion

Take one node from the unsorted portion,
find its correct position in the sorted portion,
and insert it by changing pointers.

A dummy node is used to simplify insertion
at the beginning of the sorted list.

Time Complexity:
O(n^2)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode dummy(INT_MIN);
        dummy.next = head;

        ListNode* current = head->next;

        // Separate the first node as the initial sorted portion.
        head->next = nullptr;

        while (current) {
            ListNode* nextNode = current->next;

            ListNode* prev = &dummy;

            // Find the correct insertion position.
            while (prev->next &&
                   prev->next->val < current->val) {
                prev = prev->next;
            }

            // Insert current between prev and prev->next.
            current->next = prev->next;
            prev->next = current;

            current = nextNode;
        }

        return dummy.next;
    }
};