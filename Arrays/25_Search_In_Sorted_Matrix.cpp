/*
Problem:
Search for a target in a matrix where every row and
column is sorted in ascending order.

Input:
1  4  7 11
2  5  8 12
3  6  9 16
10 13 14 17

Target:
5

Output:
Found

Approach:
Start from the top-right corner.

If current element == target:
    Target found.

If current element > target:
    Move left.

If current element < target:
    Move down.

TC: O(n + m)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> a = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;

    int n = a.size();
    int m = a[0].size();

    int i = 0;
    int j = m - 1;

    bool found = false;

    while (i < n && j >= 0) {
        if (a[i][j] == target) {
            found = true;
            break;
        }
        else if (a[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
    }

    if (found)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}