/*
Problem:
Implement a queue using stacks.

Input:
push(10), push(20), push(30), pop()

Output:
Front element = 20

Approach:
1. Brute:
   Use a stack directly, but this follows LIFO,
   so it cannot directly behave like a queue.

2. Optimal:
   Use an input stack and an auxiliary stack.
   Move all existing elements to the auxiliary stack.
   Push the new element, then move everything back.
   This keeps the oldest element at the top.

Time Complexity:
push : O(n)
pop  : O(1)
front: O(1)

Space Complexity:
O(n)

Key Insight:
Reverse the stack order during insertion so that the
oldest element remains accessible at the top.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> st;
    stack<int> temp;

public:
    void push(int x) {
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int front() {
        if (st.empty()) {
            return -1;
        }

        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};