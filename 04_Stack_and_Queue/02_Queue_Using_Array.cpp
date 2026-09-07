/*
Problem:
Implement a queue using an array.

Input:
enqueue(10), enqueue(20), enqueue(30), dequeue()

Output:
Front element = 20

Approach:
1. Brute:
   Not applicable because queue operations are directly
   implemented using an array.

2. Optimal:
   Maintain two pointers:
   first points to the front element.
   last points to the next available position.

Time Complexity:
enqueue : O(1)
dequeue : O(1)

Space Complexity:
O(n)

Key Insight:
A queue follows FIFO — First In, First Out.
The first inserted element is removed first.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int arr[1000];
    int first;
    int last;

public:
    Queue() {
        first = 0;
        last = 0;
    }

    void enqueue(int x) {
        if (last == 1000) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[last] = x;
        last++;
    }

    void dequeue() {
        if (first == last) {
            cout << "Queue Underflow\n";
            return;
        }

        first++;
    }

    int front() {
        if (first == last) {
            return -1;
        }

        return arr[first];
    }

    bool empty() {
        return first == last;
    }
};