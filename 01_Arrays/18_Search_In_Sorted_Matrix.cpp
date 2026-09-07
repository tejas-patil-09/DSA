/*
Problem:
Search for a target in a matrix sorted row-wise and column-wise.

Input:
1  4  7  11
2  5  8  12
3  6  9  16
10 13 14 17

Target:
14

Output:
Found

Approach:
Start from the top-right corner.
If the current value is greater than target, move left.
If it is smaller, move down.

Time Complexity:
O(n + m)

Space Complexity:
O(1)

Key Insight:
Each move eliminates either an entire row or an entire column.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int n = 4, m = 4;
    int target = 14;

    int i = 0, j = m - 1;

    while (i < n && j >= 0) {

        if (a[i][j] == target) {
            cout << "Found";
            break;
        }
        else if (a[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
    }

    return 0;
}