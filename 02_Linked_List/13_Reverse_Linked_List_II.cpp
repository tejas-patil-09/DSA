/*
Problem:
Reverse the nodes of a linked list from position left
to position right.

Input:
1 -> 2 -> 3 -> 4 -> 5
left = 2, right = 4

Output:
1 -> 4 -> 3 -> 2 -> 5

Brute:
Store the values from left to right, reverse them, and
put them back into the list.

Optimal:
Use a dummy node and reverse the required section in-place.

TC: O(n)
SC: O(1)

Key Insight:
The dummy node makes the case where left = 1 work without
special handling.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* before = &dummy;

        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        ListNode* curr = before->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* moveNode = curr->next;

            curr->next = moveNode->next;
            moveNode->next = before->next;
            before->next = moveNode;
        }

        return dummy.next;
    }
};