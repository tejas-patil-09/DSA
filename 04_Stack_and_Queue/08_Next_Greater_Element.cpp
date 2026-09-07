/*
Problem:
Given an array, find the next greater element for every
element. If no greater element exists, return -1.

Input:
An integer array nums.

Output:
An array where each element contains the next greater
element to its right, or -1 if none exists.

Approach:
1. Brute:
   For every element, scan all elements to its right until
   a greater element is found.
   Time Complexity: O(n^2)

2. Optimal:
   Traverse the array from right to left.
   Maintain a monotonic decreasing stack.
   Remove all elements smaller than or equal to the current
   element because they cannot be the next greater element
   for the current or any earlier smaller element.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Each element is pushed and popped from the stack at most once,
so the total work is linear.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(nums[i]);
        }

        return ans;
    }
};