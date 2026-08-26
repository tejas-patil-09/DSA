/*
Problem:
Rotate an n x n matrix by 90 degrees clockwise.

Input:
1 2 3
4 5 6
7 8 9

Output:
7 4 1
8 5 2
9 6 3

Approach:
1. Transpose the matrix.
2. Reverse every row.

Time Complexity:
O(n²)

Space Complexity:
O(1)

Key Insight:
Transpose + row reversal produces a 90° clockwise rotation in-place.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(a[i], a[i] + n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}