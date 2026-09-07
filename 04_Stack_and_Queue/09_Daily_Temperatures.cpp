/*
Problem:
Given an array of daily temperatures, return an array where
answer[i] is the number of days until a warmer temperature.
If no warmer day exists, answer[i] is 0.

Input:
An integer array temperatures.

Output:
An integer array containing the waiting days for a warmer
temperature.

Approach:
1. Brute:
   For every day, scan the days to its right until a warmer
   temperature is found.
   Time Complexity: O(n^2)

2. Optimal:
   Traverse from right to left using a monotonic decreasing
   stack of indices.
   Remove indices whose temperatures are smaller than or equal
   to the current temperature.
   The remaining top index gives the next warmer day.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Store indices instead of temperatures because the answer
requires the distance between two days.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }

        return ans;
    }
};