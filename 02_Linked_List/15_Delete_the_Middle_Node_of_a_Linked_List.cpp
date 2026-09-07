/*
Problem:
Delete the middle node of a singly linked list.
For an even-sized list, delete the second middle node.

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 2 -> 4 -> 5

Approach:

1. Brute:
   Traverse the list to count the number of nodes,
   then traverse again to reach the node before the middle
   and delete the middle node.

2. Optimal:
   Use slow and fast pointers.
   Slow moves one step while fast moves two steps.
   Keep track of the node before slow.
   When fast reaches the end, slow is the middle node.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;

        return head;
    }
};