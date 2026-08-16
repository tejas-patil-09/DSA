/*
Problem:
Given n distinct numbers from the range [0, n],
find the missing number.

Input:
3 0 1

Output:
2

Approach:
Use XOR.
Equal numbers cancel each other.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {3, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);

    int ans = n;

    for (int i = 0; i < n; i++) {
        ans ^= i;
        ans ^= a[i];
    }

    cout << ans << endl;

    return 0;
}