/*
Problem:
Implement a Doubly Linked List with the following operations:

1. insertAtHead(val)
2. insertAtTail(val)
3. insertAtIndex(index, val)
4. deleteAtHead()
5. deleteAtTail()
6. deleteAtIndex(index)
7. get(index)

Each node contains:
- val
- prev
- next

The list uses 0-based indexing.

Approach:

Maintain two pointers:
- head -> first node
- tail -> last node

Unlike a singly linked list, every node has two connections:
- prev -> previous node
- next -> next node

For insertion or deletion, both directions must be updated.

For insertion at an index:
1. Traverse to the node currently at that index.
2. Create the new node.
3. Connect newNode->prev and newNode->next.
4. Update the neighboring nodes' pointers.

For deletion:
1. Find the target node.
2. Connect its previous node to its next node.
3. Connect its next node back to its previous node.
4. Delete the target node.

Key Insight:
In a DLL, whenever you change a connection,
think in both directions:
prev <-> current <-> next

Time Complexity:
get(index): O(n)
insertAtHead(): O(1)
insertAtTail(): O(1)
insertAtIndex(): O(n)
deleteAtHead(): O(1)
deleteAtTail(): O(1)
deleteAtIndex(): O(n)

Space Complexity:
O(n)
*/

class MyDoublyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    MyDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp; i++)
            temp = temp->next;
        return temp ? temp->val : -1;
    }

    void insertAtHead(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAtTail(int val) {
        Node* node = new Node(val);

        if (!tail) {
            head = tail = node;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    void insertAtIndex(int index, int val) {
        if (index < 0)
            return;

        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index && temp; i++)
            temp = temp->next;

        if (!temp) {
            int length = 0;
            for (Node* p = head; p; p = p->next)
                length++;

            if (index == length)
                insertAtTail(val);
            return;
        }

        Node* node = new Node(val);

        node->prev = temp->prev;
        node->next = temp;
        temp->prev->next = node;
        temp->prev = node;
    }

    void deleteAtHead() {
        if (!head)
            return;

        Node* temp = head;

        if (head == tail)
            head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void deleteAtTail() {
        if (!tail)
            return;

        Node* temp = tail;

        if (head == tail)
            head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || !head)
            return;

        if (index == 0) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index && temp; i++)
            temp = temp->next;

        if (!temp)
            return;

        if (temp == tail) {
            deleteAtTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
};
