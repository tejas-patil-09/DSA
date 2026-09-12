/*
Problem:
Reverse the nodes of a linked list k at a time.
If the remaining nodes are fewer than k, leave them unchanged.

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
2 -> 1 -> 4 -> 3 -> 5

Approach:

1. Brute:
   Store the nodes in an array/vector and reverse every
   group of k nodes.

2. Optimal:
   Find whether k nodes are available.
   Reverse the group in-place.
   Connect the reversed group with the previous group.
   Repeat until fewer than k nodes remain.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* nextGroup = tail->next;
        ListNode* prev = nextGroup;
        ListNode* curr = head;

        while(curr != nextGroup) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode* before = &dummy;

        while(true) {
            ListNode* temp = before;

            for(int i = 0; i < k && temp; i++)
                temp = temp->next;

            if(!temp)
                break;

            ListNode* groupHead = before->next;

            before->next = reverseList(groupHead, temp);

            before = groupHead;
        }

        return dummy.next;
    }
};