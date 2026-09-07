/*
Problem:
Given an array of bar heights representing a histogram,
find the largest rectangular area in the histogram.

Input:
An integer array heights.

Output:
The maximum rectangular area.

Approach:
1. Brute:
   For every bar, expand left and right while the bars are
   greater than or equal to its height.
   Time Complexity: O(n^2)

2. Optimal:
   Use a monotonic increasing stack of indices.
   When a smaller height is found, calculate the area of
   rectangles using the popped bars as the minimum height.
   The width is determined by the nearest smaller bars
   on both sides.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
For every bar, find the largest width in which that bar
can act as the minimum height.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() &&
                   heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();

                int leftBoundary = st.empty() ? -1 : st.top();
                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};