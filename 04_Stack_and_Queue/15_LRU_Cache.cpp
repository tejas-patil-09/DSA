/*
Problem:
Design a data structure that supports get and put operations
for a Least Recently Used (LRU) cache.

Input:
A cache capacity and a sequence of get and put operations.

Output:
The value for get operations, or -1 if the key is absent.

Approach:
1. Brute:
   Use a list to store keys in usage order.
   Searching and moving a key takes O(n).

2. Optimal:
   Use:
   - HashMap to find a key in O(1).
   - Doubly linked list to maintain usage order.

   The most recently used node is placed after the head.
   The least recently used node is placed before the tail.

Time Complexity:
O(1) for get and put.

Space Complexity:
O(capacity)

Key Insight:
A HashMap provides fast access, while a doubly linked list
provides fast insertion and deletion.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
    };

    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node{0, 0, nullptr, nullptr};
        tail = new Node{0, 0, nullptr, nullptr};

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            insertAfterHead(node);

            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node{key, value, nullptr, nullptr};

        mp[key] = node;
        insertAfterHead(node);
    }
};