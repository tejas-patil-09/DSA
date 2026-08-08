/*
Problem:
Merge two sorted linked lists into one sorted linked list.

Input:
list1 = 1 -> 2 -> 4
list2 = 1 -> 3 -> 4

Output:
1 -> 1 -> 2 -> 3 -> 4 -> 4

Brute:
Store the values of both lists in an array/vector,
sort them, and create/modify the linked list.

Optimal:
Use two pointers to compare the current nodes of both
lists and attach the smaller node to the result.

TC: O(n + m)
SC: O(1)

Key Insight:
Use a dummy node to avoid separately handling the first
node of the merged list.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy.next;
    }
};