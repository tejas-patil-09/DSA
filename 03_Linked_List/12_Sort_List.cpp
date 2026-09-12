/*
Problem:
Sort a linked list in ascending order.

Input:
4 -> 2 -> 1 -> 3

Output:
1 -> 2 -> 3 -> 4

Brute:
Store all values in an array/vector, sort them, and
update the linked list.

Optimal:
Use merge sort:
1. Find the middle of the list.
2. Split the list into two halves.
3. Recursively sort both halves.
4. Merge the two sorted halves.

TC: O(n log n)
SC: O(log n) due to recursion stack

Key Insight:
Merge sort is well suited for linked lists because lists
can be split and merged without shifting elements.
*/

class Solution {
public:
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (head1 && head2) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        if (head1)
            temp->next = head1;
        else
            temp->next = head2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return mergeList(left, right);
    }
};