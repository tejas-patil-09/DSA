/*
Problem:
Find the largest element in an array.

Input:
{5, 3, 8, 1, 9}

Output:
9

Approach:
Traverse the array while maintaining the maximum element seen so far.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Keep updating the maximum whenever a larger element is found.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = 5;

    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        maximum = max(maximum, arr[i]);
    }

    cout << maximum;

    return 0;
}