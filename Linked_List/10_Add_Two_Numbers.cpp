/*
Problem:
Add two numbers represented by linked lists.
The digits are stored in reverse order.

Input:
l1 = 2 -> 4 -> 3
l2 = 5 -> 6 -> 4

Output:
7 -> 0 -> 8

Explanation:
342 + 465 = 807

Brute:
Convert both linked lists into numbers, add them, and
create a linked list from the result.

Optimal:
Traverse both lists simultaneously and add corresponding
digits along with the carry.

TC: O(max(n, m))
SC: O(max(n, m)) for the output list

Key Insight:
Each node represents one digit, so addition can be done
exactly like normal addition from right to left because
the digits are already stored in reverse order.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy.next;
    }
};