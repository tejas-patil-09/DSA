/*
Problem:
Design an LFU (Least Frequently Used) Cache.

Operations:
1. get(key)
2. put(key, value)

Requirements:
- get() should work in O(1) average time.
- put() should work in O(1) average time.

Eviction Rules:
1. Remove the least frequently used key.
2. If multiple keys have the same frequency,
   remove the least recently used key.

Approach:

Use three main components:

1. HashMap:
   key -> DLL node

   This gives direct access to a key's node in O(1).

2. HashMap:
   frequency -> Doubly Linked List

   Each frequency has its own DLL containing all nodes
   having that frequency.

3. minFreq:
   Stores the minimum frequency currently present.

For every frequency DLL:
- Front = most recently used
- Back = least recently used

When get(key) or put(existing key) is called:
1. Find the node using keyToNode.
2. Remove it from its current frequency list.
3. Increase its frequency.
4. Insert it at the front of the new frequency list.
5. Update minFreq when necessary.

When the cache is full:
1. Go to the DLL corresponding to minFreq.
2. Remove the node from the back.
3. This automatically gives the LFU + LRU tie-breaking behavior.

Key Insight:
HashMap gives O(1) access to the node.
DLL gives O(1) removal/insertion and LRU ordering.
Frequency HashMap groups nodes by frequency.
minFreq tells us exactly where the eviction candidate is.

Time Complexity:
O(1) average for get()
O(1) average for put()

Space Complexity:
O(capacity)
*/

#include <unordered_map>
using namespace std;

class LFUCache {
    struct Node {
        int key, value, freq;
        Node *prev, *next;

        Node(int k, int v)
            : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct DLL {
        Node *head, *tail;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = node->next = nullptr;
        }

        Node* removeBack() {
            if (head->next == tail)
                return nullptr;
            Node* node = tail->prev;
            remove(node);
            return node;
        }

        bool empty() {
            return head->next == tail;
        }
    };

    int capacity, minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DLL*> freqToList;

    void increaseFrequency(Node* node) {
        int oldFreq = node->freq;
        DLL* oldList = freqToList[oldFreq];

        oldList->remove(node);

        if (oldList->empty() && minFreq == oldFreq)
            minFreq++;

        node->freq++;

        if (!freqToList.count(node->freq))
            freqToList[node->freq] = new DLL();

        freqToList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyToNode.count(key))
            return -1;

        Node* node = keyToNode[key];
        increaseFrequency(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToNode.count(key)) {
            Node* node = keyToNode[key];
            node->value = value;
            increaseFrequency(node);
            return;
        }

        if ((int)keyToNode.size() == capacity) {
            Node* victim = freqToList[minFreq]->removeBack();
            keyToNode.erase(victim->key);
            delete victim;
        }

        Node* node = new Node(key, value);

        if (!freqToList.count(1))
            freqToList[1] = new DLL();

        freqToList[1]->addFront(node);
        keyToNode[key] = node;
        minFreq = 1;
    }
};
