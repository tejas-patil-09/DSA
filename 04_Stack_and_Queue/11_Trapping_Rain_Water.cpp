/*
Problem:
Given an array representing elevation heights, calculate
how much rainwater can be trapped between the bars.

Input:
An integer array height.

Output:
The total amount of trapped rainwater.

Approach:
1. Brute:
   For every position, find the maximum height on its left
   and right.
   Water at that position is:
   min(leftMax, rightMax) - height[i]
   Time Complexity: O(n^2)

2. Optimal:
   Use two pointers and maintain leftMax and rightMax.
   Process the side with the smaller height because the
   smaller side determines the trapped water.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Water level is limited by the smaller boundary, so we can
process that side without knowing the exact opposite maximum.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    water += leftMax - height[left];
                }

                left++;
            }
            else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    water += rightMax - height[right];
                }

                right--;
            }
        }

        return water;
    }
};