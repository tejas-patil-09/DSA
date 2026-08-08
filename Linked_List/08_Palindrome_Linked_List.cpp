/*
Problem:
Check whether a linked list is a palindrome.

Input:
1 -> 2 -> 2 -> 1

Output:
true

Brute:
Store the node values in an array/vector and compare
values from both ends.

Optimal:
Find the middle using slow and fast pointers.
Reverse the second half and compare it with the first half.

TC: O(n)
SC: O(1)

Key Insight:
After finding the middle, reversing the second half allows
both halves to be compared from left to right.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextNode = head->next;

            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = reverseList(slow);

        ListNode* first = head;
        ListNode* second = secondHead;

        while (second) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};