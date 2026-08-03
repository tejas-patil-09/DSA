/*
==========================================================
            SEARCH A 2D MATRIX II
==========================================================

Problem:
Search a target in a row-wise and column-wise
sorted matrix.

Approach:
- Start from the top-right corner.
- Eliminate one row or one column in each step.

TC : O(n + m)
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int rsize = matrix.size(), csize = matrix[0].size();
    int row = 0, col = csize - 1;

    while (row < rsize && col >= 0)
    {
        int curVal = matrix[row][col];
        if (curVal == target)
        {
            return true;
        }
        else if (curVal > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    cout << searchMatrix(matrix, 30);

    return 0;
}