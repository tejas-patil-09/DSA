/*
Problem:
Design a singly linked list supporting:

1. get(index)
2. addAtHead(val)
3. addAtTail(val)
4. addAtIndex(index, val)
5. deleteAtIndex(index)

Indexing is 0-based.

Approach:
Use a singly linked list.

For insertion/deletion at a given index,
traverse to the previous node and modify pointers.

Time Complexity:
get()          -> O(n)
addAtHead()    -> O(1)
addAtTail()    -> O(n)
addAtIndex()   -> O(n)
deleteAtIndex()-> O(n)

Space Complexity:
O(n)
*/

class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int v) {
            val = v;
            next = nullptr;
        }
    };

    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;

        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }

        if (!temp)
            return -1;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (!head)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;

            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next)
            return;

        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
    }
};