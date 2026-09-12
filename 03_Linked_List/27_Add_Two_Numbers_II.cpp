/*
Problem:
Add two numbers represented by linked lists.

Digits are stored in forward order.

Input:
7 -> 2 -> 4 -> 3
5 -> 6 -> 4

Output:
7 -> 8 -> 0 -> 7

Approach:
Reverse both input lists so that addition starts
from the least significant digit.

Perform normal addition with carry.

Finally reverse the result to restore forward order.

Time Complexity:
O(n + m)

Space Complexity:
O(1) auxiliary space

Note:
This approach temporarily modifies the input lists.
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* nextNode = cur->next;

            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* newList = &dummy;

        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);

        int carry = 0;

        while (rl1 || rl2) {
            int sum = carry;

            if (rl1) {
                sum += rl1->val;
                rl1 = rl1->next;
            }

            if (rl2) {
                sum += rl2->val;
                rl2 = rl2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            newList->next = new ListNode(digit);
            newList = newList->next;
        }

        if (carry) {
            newList->next = new ListNode(carry);
        }

        return reverse(dummy.next);
    }
};