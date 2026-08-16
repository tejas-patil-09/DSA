/*
Problem:
Left rotate an array by k positions.

Input:
1 2 3 4 5 6 7
k = 3

Output:
4 5 6 7 1 2 3

Approach:
Use the reversal algorithm:
1. Reverse the first k elements.
2. Reverse the remaining elements.
3. Reverse the entire array.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    k %= n;

    reverse(a, a + k);
    reverse(a + k, a + n);
    reverse(a, a + n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}