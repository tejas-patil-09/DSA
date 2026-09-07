/*
Problem:
Evaluate an arithmetic expression written in Reverse Polish
Notation (postfix notation).

Input:
A vector of strings containing integers and operators
'+', '-', '*' and '/'.

Output:
The evaluated integer result.

Approach:
1. Brute:
   Convert the postfix expression into an infix expression
   and then evaluate it.
   This requires extra processing and is unnecessary.

2. Optimal:
   Use a stack.
   - Push every number.
   - When an operator appears, pop the second operand first,
     then pop the first operand.
   - Apply the operator and push the result.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
In postfix notation, the operands required by an operator
are always the two most recent available values.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                int result;

                if (token == "+") {
                    result = first + second;
                }
                else if (token == "-") {
                    result = first - second;
                }
                else if (token == "*") {
                    result = first * second;
                }
                else {
                    result = first / second;
                }

                st.push(result);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};