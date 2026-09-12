/*
Problem:
Find the node at which two singly linked lists intersect.
Return nullptr if they do not intersect.

Input:
List A: 4 -> 1 -> 8 -> 4 -> 5
List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5

Output:
Node with value 8

Brute:
Store all nodes of the first list in an unordered_set.
Traverse the second list and return the first node that
already exists in the set.

Optimal:
Find the lengths of both lists.
Move the pointer of the longer list forward by the length
difference, then move both pointers together until they
point to the same node.

TC: O(n + m)
SC: O(1)

Key Insight:
Intersection means the actual node is shared, so compare
pointers rather than node values.
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0;
        int lengthB = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA) {
            lengthA++;
            tempA = tempA->next;
        }

        while (tempB) {
            lengthB++;
            tempB = tempB->next;
        }

        if (lengthA > lengthB) {
            int diff = lengthA - lengthB;

            while (diff--) {
                headA = headA->next;
            }
        } else {
            int diff = lengthB - lengthA;

            while (diff--) {
                headB = headB->next;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};