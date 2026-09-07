/*
Problem:
Implement a stack using an array.

Input:
push(10), push(20), push(30), pop()

Output:
Top element = 20

Approach:
1. Brute:
   Not applicable because stack operations are directly
   implemented using an array.

2. Optimal:
   Maintain a topIndex pointing to the top element.
   Insert and remove elements using this index.

Time Complexity:
push : O(1)
pop  : O(1)
top  : O(1)

Space Complexity:
O(n)

Key Insight:
A stack follows LIFO — Last In, First Out.
The most recently inserted element is removed first.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[1000];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == 999) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            return -1;
        }

        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};