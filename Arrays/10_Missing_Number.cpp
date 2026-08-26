
/*
Problem:
Find the missing number from an array containing numbers from 0 to n.

Input:
{3, 0, 1}

Output:
2

Approach:
XOR all numbers from 0 to n with all elements of the array.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
x ^ x = 0, so every present number cancels itself and only the missing
number remains.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 0, 1};
    int n = 3;

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        ans ^= i;
    }

    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    cout << ans;

    return 0;
}