/*
Problem:
Move all zeroes to the end while maintaining the
relative order of non-zero elements.

Input:
0 1 0 3 12

Output:
1 3 12 0 0

Approach:
Use two pointers.
j represents the position where the next non-zero
element should be placed.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {0, 1, 0, 3, 12};
    int n = sizeof(a) / sizeof(a[0]);

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}