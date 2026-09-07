/*
Problem:
Design an LRU (Least Recently Used) Cache.

Operations:
1. get(key)  -> return value if present, otherwise -1.
2. put(key, value) -> insert/update the key.

When capacity is exceeded, remove the least recently used key.

Approach:
Use a HashMap + Doubly Linked List.

HashMap:
key -> Node*
Provides O(1) access to a node.

Doubly Linked List:
Head -> Most Recently Used
Tail -> Least Recently Used

On get():
- Find node in HashMap.
- Remove it from its current position.
- Move it to the head.

On put():
- If key exists, update value and move node to head.
- Otherwise create a new node and add it to head.
- If capacity is exceeded, remove the node before tail.

Time Complexity:
O(1) for get() and put()

Space Complexity:
O(capacity)
*/

class LRUCache {
    struct Node {
        int key;
        int val;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int capacity;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        removeNode(node);
        addToHead(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            removeNode(node);
            addToHead(node);
            return;
        }

        Node* newNode = new Node(key, value);

        mp[key] = newNode;
        addToHead(newNode);

        if (mp.size() > capacity) {
            Node* lru = tail->prev;

            mp.erase(lru->key);
            removeNode(lru);

            delete lru;
        }
    }
};