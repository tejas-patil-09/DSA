/*
Problem:
Partition a linked list around a value x.
All nodes with values less than x should come before
nodes with values greater than or equal to x.
The relative order must be preserved.

Input:
1 -> 4 -> 3 -> 2 -> 5 -> 2
x = 3

Output:
1 -> 2 -> 2 -> 4 -> 3 -> 5

Approach:

1. Brute:
   Store nodes in separate arrays/vectors based on whether
   their value is less than x or greater than/equal to x,
   then rebuild the list.

2. Optimal:
   Maintain two linked lists:
   one for values less than x and one for values greater
   than or equal to x.
   Connect the two lists at the end.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;

        ListNode* temp = head;

        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;

        while(temp) {
            if(temp->val >= x) {
                greaterTail->next = temp;
                greaterTail = greaterTail->next;
            }
            else {
                lessTail->next = temp;
                lessTail = lessTail->next;
            }

            temp = temp->next;
        }

        greaterTail->next = nullptr;
        lessTail->next = greaterDummy.next;

        return lessDummy.next;
    }
};
