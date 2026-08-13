/*
Problem:
Create a deep copy of a linked list where every node has
a next pointer and a random pointer.

Input:
[[-1,0],[-2,0]]

Output:
[[-1,0],[-2,0]]

Approach:

1. Brute:
   Use a HashMap to map each original node to its copied node.
   First create all copied nodes, then assign their next and
   random pointers using the map.

2. Optimal:
   Insert each copied node directly after its original node.
   This allows the random pointer of a copied node to be found
   using originalRandom->next.
   Finally separate the original and copied lists.

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;

        Node* temp = head;

        while(temp) {
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        temp = head;

        while(temp) {
            Node* copy = temp->next;

            if(temp->random)
                copy->random = temp->random->next;

            temp = copy->next;
        }

        Node* newHead = head->next;
        temp = head;

        while(temp) {
            Node* copy = temp->next;

            temp->next = copy->next;

            if(temp->next)
                copy->next = temp->next->next;

            temp = temp->next;
        }

        return newHead;
    }
};