/*
Problem:
Find the element that appears only once while every other element appears twice.

Input:
{4, 1, 2, 1, 2}

Output:
4

Approach:
XOR all elements.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Pairs cancel because x ^ x = 0, leaving the single element.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = 5;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    cout << ans;

    return 0;
}