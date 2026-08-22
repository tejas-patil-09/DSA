/*
Problem:
Find the row with the maximum number of 1s in a binary
matrix where each row is sorted.

Input:
0 0 0 1
0 0 1 1
0 1 1 1
0 0 0 0

Output:
Row 2

Approach:
Start from the top-right corner.

If current element is 1:
    Move left and update the answer.

If current element is 0:
    Move down.

TC: O(n + m)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int n = a.size();
    int m = a[0].size();

    int row = -1;
    int j = m - 1;

    for (int i = 0; i < n; i++) {
        while (j >= 0 && a[i][j] == 1) {
            row = i;
            j--;
        }
    }

    if (row != -1)
        cout << "Row " << row << endl;
    else
        cout << "No row contains 1" << endl;

    return 0;
}