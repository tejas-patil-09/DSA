/*
==========================================================
            BASIC LINKED LIST OPERATIONS
==========================================================

Operations Implemented:
1. Insert at End
2. Print List
3. Count Nodes
4. Search Node
5. Insert at Beginning
6. Insert at Position
7. Delete Head
8. Delete Tail
9. Delete at Position

Time Complexity:
• Insert at End        : O(n)
• Print                : O(n)
• Count Nodes          : O(n)
• Search               : O(n)
• Insert at Beginning  : O(1)
• Insert at Position   : O(n)
• Delete Head          : O(1)
• Delete Tail          : O(n)
• Delete at Position   : O(n)
*/



#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int countNodes(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
            return true;

        temp = temp->next;
    }
    return false;
}

void insertAtBegin(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node *&head, int position, int data)
{

    if (position == 1)
    {
        insertAtBegin(head, data);
        return;
    }

    Node *newNode = new Node(data);

    Node *temp = head;

    // Move to the node just before the insertion position
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead(Node *&head)
{
    if (!head)
        return;
    Node *temp = head;
    head = head->next;

    delete temp;
}

void deleteTail(Node *&head)
{
    if (!head)
        return;

    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(Node *&head, int position)
{
    if (position == 1)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}



int main()
{
    Node* head = nullptr;

    // Create Linked List
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Initial List:\n";
    print(head);

    cout << "\n\nTotal Nodes: " << countNodes(head);

    cout << "\nSearch 20: "
         << (search(head, 20) ? "Found" : "Not Found");

    cout << "\nSearch 100: "
         << (search(head, 100) ? "Found" : "Not Found");

    // Insert Operations
    insertAtBegin(head, 5);

    insertAtPosition(head, 3, 15);

    cout << "\n\nAfter Insertions:\n";
    print(head);

    // Delete Operations
    deleteHead(head);

    deleteTail(head);

    deleteAtPosition(head, 2);

    cout << "\n\nAfter Deletions:\n";
    print(head);

    // Free allocated memory
    while(head != nullptr)
    {
        deleteHead(head);
    }

    return 0;
}