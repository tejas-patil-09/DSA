/*
Problem:
Every element appears twice except one.
Find the element that appears only once.

Input:
4 1 2 1 2

Output:
4

Approach:
XOR all elements.
Equal elements cancel each other.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {4, 1, 2, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= a[i];
    }

    cout << ans << endl;

    return 0;
}