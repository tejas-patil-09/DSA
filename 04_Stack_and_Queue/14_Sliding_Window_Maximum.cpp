/*
Problem:
Given an integer array nums and an integer k, return the
maximum value in every contiguous subarray of size k.

Input:
An integer array nums and an integer k.

Output:
An array containing the maximum value of every window.

Approach:
1. Brute:
   For every window, scan all k elements to find the maximum.
   Time Complexity: O(n * k)

2. Optimal:
   Use a deque storing indices.
   Maintain decreasing values from front to back.
   Remove indices outside the current window.
   Remove smaller values from the back because they cannot
   become the maximum while the current value is present.

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
The deque stores only useful candidates for the maximum
of the current window.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() &&
                   nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};