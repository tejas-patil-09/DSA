/*
Problem:
Remove duplicate values from a sorted linked list.
Keep only one occurrence of each value.

Input:
1 -> 1 -> 2 -> 3 -> 3

Output:
1 -> 2 -> 3

Approach:

1. Brute:
   Store the values in a data structure and create/remove
   duplicate nodes based on the stored values.

2. Optimal:
   Since the list is sorted, duplicates are adjacent.
   Compare the current node with the previous node.
   If both values are equal, remove the current node.
   Otherwise move both pointers forward.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr) {
            if(curr->val == prev->val) {
                ListNode* toDelete = curr;
                curr = curr->next;
                prev->next = curr;
                delete toDelete;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
