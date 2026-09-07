/*
Problem:
Find the index of a target element using linear search.

Input:
{5, 3, 8, 1, 9}, target = 8

Output:
2

Approach:
Traverse the array from left to right until the target is found.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Check each element sequentially until the target is found.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = 5, target = 8;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}