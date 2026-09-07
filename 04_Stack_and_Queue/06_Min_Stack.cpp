/*
Problem:
Design a stack that supports push, pop, top and retrieving
the minimum element in constant time.

Input:
Operations involving integers.

Output:
The result of the requested operations.

Approach:
1. Brute:
   Use one stack and scan all elements whenever the minimum
   is required.
   getMin() takes O(n).

2. Optimal:
   Use two stacks:
   - Main stack stores all elements.
   - Minimum stack stores the minimum element at each level.

   Whenever an element smaller than or equal to the current
   minimum is pushed, push it into the minimum stack.
   Remove it when it is popped.

Time Complexity:
O(1) for every operation.

Space Complexity:
O(n)

Key Insight:
The minimum stack remembers the minimum value corresponding
to every important state of the main stack.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};