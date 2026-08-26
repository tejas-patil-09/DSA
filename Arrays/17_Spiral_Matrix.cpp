/*
Problem:
Traverse a matrix in spiral order.

Input:
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Approach:
Maintain four boundaries: top, bottom, left and right. Traverse one
boundary at a time and shrink it after each traversal.

Time Complexity:
O(n × m)

Space Complexity:
O(1)

Key Insight:
The four boundaries define the unvisited portion of the matrix.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int top = 0, bottom = 2;
    int left = 0, right = 2;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            cout << a[top][i] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << a[bottom][i] << " ";
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }
    }

    return 0;
}