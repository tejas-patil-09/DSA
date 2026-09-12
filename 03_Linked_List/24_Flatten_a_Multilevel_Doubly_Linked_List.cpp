/*
Problem:
Flatten a multilevel doubly linked list into a single-level
doubly linked list.

Input:
1 <-> 2 <-> 3 <-> 4
          |
          7 <-> 8 <-> 9
                 |
                 10

Output:
1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 9 <-> 10 <-> 4

Approach:

1. Brute:
   Traverse the child list separately, find its tail,
   connect it with the original next node, and continue.
   Repeatedly finding child tails can cause extra traversal.

2. Optimal:
   Recursively flatten each child list.
   The helper returns the tail of the flattened child list.
   Use this tail to directly reconnect the original next node.

   For every child:
   - Save the original next node.
   - Connect current node to the child list.
   - Recursively flatten the child list.
   - Connect the child tail to the saved next node.
   - Continue traversing the list.

Time Complexity:
O(n)

Space Complexity:
O(n) due to recursion stack in the worst case.
*/

class Solution {
public:
    Node* flattenList(Node* head) {
        Node* cur = head;

        while(cur) {
            if(cur->child) {
                Node* child = cur->child;
                Node* next = cur->next;

                cur->next = child;
                child->prev = cur;
                cur->child = nullptr;

                Node* childTail = flattenList(child);

                childTail->next = next;

                if(next)
                    next->prev = childTail;
            }

            if(!cur->next)
                return cur;

            cur = cur->next;
        }

        return cur;
    }

    Node* flatten(Node* head) {
        if(!head)
            return head;

        flattenList(head);

        return head;
    }
};