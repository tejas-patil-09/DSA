/*
Problem:
Swap every two adjacent nodes in a linked list.

Input:
1 -> 2 -> 3 -> 4

Output:
2 -> 1 -> 4 -> 3

Approach:

1. Brute:
   Store the values in an array/vector and swap adjacent
   values, then update the list.

2. Optimal:
   Swap the nodes directly using pointers.
   Maintain a pointer to the previous pair so that the
   swapped pair can be connected to the rest of the list.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* beforeLink = nullptr;

        while(temp && temp->next) {
            ListNode* prev = temp;

            temp = temp->next;

            prev->next = temp->next;
            temp->next = prev;

            if(beforeLink)
                beforeLink->next = temp;
            else
                head = temp;

            beforeLink = prev;
            temp = prev->next;
        }

        return head;
    }
};