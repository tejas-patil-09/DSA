/*
Problem:
Print all elements of a matrix in spiral order.

Input:
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Approach:
Maintain four boundaries:
top, bottom, left and right.

Traverse:
1. Left to right
2. Top to bottom
3. Right to left
4. Bottom to top

Shrink the boundaries after each traversal.

TC: O(n * m)
SC: O(1) excluding output storage
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
    int m = a[0].size();

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    while (top <= bottom && left <= right) {

        for (int j = left; j <= right; j++)
            cout << a[top][j] << " ";

        top++;

        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";

        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << a[bottom][j] << " ";

            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";

            left++;
        }
    }

    cout << endl;

    return 0;
}