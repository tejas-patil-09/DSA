/*
Problem:
Remove the nth node from the end of a linked list.

Input:
1 -> 2 -> 3 -> 4 -> 5, n = 2

Output:
1 -> 2 -> 3 -> 5

Brute:
Count the total number of nodes, calculate the position
from the beginning, then remove that node.

Optimal:
Use two pointers with a gap of n nodes.
Move fast n+1 steps ahead using a dummy node.
Then move both pointers until fast reaches the end.
The node after slow is the node to remove.

TC: O(n)
SC: O(1)

Key Insight:
The dummy node makes deleting the head work the same way
as deleting any other node.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* toRemove = slow->next;
        slow->next = toRemove->next;

        delete toRemove;

        return dummy.next;
    }
};