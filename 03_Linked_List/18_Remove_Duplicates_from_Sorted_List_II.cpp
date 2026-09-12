/*
Problem:
Remove all nodes that have duplicate values.
Only values appearing exactly once should remain.

Input:
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

Output:
1 -> 2 -> 5

Approach:

1. Brute:
   Store the frequency of every value using a HashMap.
   Traverse the list again and keep only nodes whose
   frequency is 1.

2. Optimal:
   Since the list is sorted, duplicate values appear together.
   Use a dummy node and detect each duplicate group.
   If a group contains duplicates, remove the entire group.
   Otherwise move prev forward.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    void deleteList(ListNode* &head) {
        while(head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr) {
            bool duplicate = false;

            while(curr->next && curr->val == curr->next->val) {
                curr = curr->next;
                duplicate = true;
            }

            if(duplicate) {
                ListNode* toDelete = prev->next;
                prev->next = curr->next;

                curr = curr->next;

                toDelete->next = nullptr;
                deleteList(toDelete);
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};