/*
Problem:
If an element in a matrix is 0, set its entire row
and column to 0.

Input:
1 1 1
1 0 1
1 1 1

Output:
1 0 1
0 0 0
1 0 1

Approach:
Use the first row and first column as markers to achieve
constant extra space.

TC: O(n * m)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    int n = a.size();
    int m = a[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int j = 0; j < m; j++) {
        if (a[0][j] == 0)
            firstRowZero = true;
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0)
            firstColZero = true;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 0) {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < m; j++)
            a[0][j] = 0;
    }

    if (firstColZero) {
        for (int i = 0; i < n; i++)
            a[i][0] = 0;
    }

    for (auto row : a) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}