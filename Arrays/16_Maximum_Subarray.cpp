/*
Problem:
Find the maximum possible sum of a contiguous subarray.

Input:
-2 1 -3 4 -1 2 1 -5 4

Output:
6

Approach:
Use Kadane's Algorithm.
Maintain the current subarray sum and maximum sum found.

If the current sum becomes negative, start a new subarray.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    int sum = 0;
    int maximum = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        maximum = max(maximum, sum);

        if (sum < 0)
            sum = 0;
    }

    cout << maximum << endl;

    return 0;
}