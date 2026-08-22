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

Brute:
Use an extra matrix and place each element at its
rotated position.

TC: O(n^2)
SC: O(n^2)

Optimal:
Transpose the matrix and then reverse every row.

TC: O(n^2)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = a.size();

    // Optimal approach
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
    }

    for (auto row : a) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}