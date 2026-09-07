/*
Problem:
Given a non-negative integer represented as a string num,
remove k digits from the number so that the new number is
the smallest possible.

Input:
A string num and an integer k.

Output:
The smallest possible number after removing k digits.

Approach:
1. Brute:
   Try different combinations of k digits and select the
   smallest resulting number.
   Time Complexity: Exponential.

2. Optimal:
   Use a monotonic increasing stack.
   Remove larger previous digits when the current digit is
   smaller and k is still greater than zero.
   If digits still need to be removed, remove them from
   the end.
   Finally, remove leading zeroes.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
To obtain the smallest number, remove a larger digit before
a smaller digit whenever possible.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char digit : num) {
            while (!st.empty() && k > 0 &&
                   st.back() > digit) {
                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        int start = 0;

        while (start < st.size() && st[start] == '0') {
            start++;
        }

        string result = st.substr(start);

        return result.empty() ? "0" : result;
    }
};