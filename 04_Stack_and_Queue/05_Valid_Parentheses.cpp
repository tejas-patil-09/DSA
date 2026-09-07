/*
Problem:
Given a string containing '(', ')', '{', '}', '[' and ']',
determine whether the input string has valid parentheses.

Input:
A string containing brackets.

Output:
true if the brackets are valid, otherwise false.

Approach:
1. Brute:
   Repeatedly remove valid adjacent pairs of brackets.
   If the string becomes empty, it is valid.
   This takes O(n^2) time.

2. Optimal:
   Use a stack.
   Push opening brackets.
   For every closing bracket, check whether it matches
   the top opening bracket.
   The string is valid only if the stack is empty at the end.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
A closing bracket must match the most recently opened
unclosed bracket, so a stack is the natural choice.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};