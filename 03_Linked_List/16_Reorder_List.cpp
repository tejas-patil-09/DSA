/*
Problem:
Reorder a linked list in the following pattern:
L0 -> L1 -> ... -> Ln-1 -> Ln

becomes:

L0 -> Ln -> L1 -> Ln-1 -> ...

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 5 -> 2 -> 4 -> 3

Approach:

1. Brute:
   Store the nodes in an array/vector and use two pointers
   from the beginning and end to reorder the list.

2. Optimal:
   1. Find the middle using slow and fast pointers.
   2. Split the list into two halves.
   3. Reverse the second half.
   4. Merge the two halves alternately.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        while(head) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* firstHead = head;
        ListNode* secondHead = reverse(slow);

        ListNode* tail = firstHead;

        while(firstHead && secondHead) {
            ListNode* firstNext = firstHead->next;
            ListNode* secondNext = secondHead->next;

            tail->next = firstHead;
            tail = tail->next;

            tail->next = secondHead;
            tail = tail->next;

            firstHead = firstNext;
            secondHead = secondNext;
        }

        if(firstHead)
            tail->next = firstHead;

        if(secondHead)
            tail->next = secondHead;
    }
};