/*
Problem:
Group all nodes at odd positions together followed by
all nodes at even positions.

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 3 -> 5 -> 2 -> 4

Brute:
Store odd-position and even-position nodes separately
and then combine them.

Optimal:
Maintain two pointers for the odd and even positions.
Connect the odd nodes together and the even nodes together,
then attach the even list after the odd list.

TC: O(n)
SC: O(1)

Key Insight:
Keep the head of the even list because it is needed to
connect it after the odd list at the end.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};