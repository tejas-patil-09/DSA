/*
Problem:
Implement a stack using a single queue.

Input:
push(10), push(20), push(30), pop()

Output:
Top element = 20

Approach:
1. Brute:
   Use a queue directly, but this follows FIFO,
   so it cannot directly behave like a stack.

2. Optimal:
   Push the new element into the queue.
   Then rotate all previous elements behind it.
   This makes the newest element appear at the front.

Time Complexity:
push : O(n)
pop  : O(1)
top  : O(1)

Space Complexity:
O(n)

Key Insight:
After every push, rotate the queue so that the newest
element stays at the front and behaves like a stack top.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int top() {
        if (q.empty()) {
            return -1;
        }

        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};