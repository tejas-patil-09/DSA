/*
==========================================================
              SEARCH A 2D MATRIX
==========================================================

Problem:
Search a target in a matrix where each row is
sorted and the first element of each row is
greater than the last element of the previous row.

Approach:
- Treat the matrix as a sorted 1D array.
- Apply Binary Search.

TC : O(log(n × m))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rsize = matrix.size(), csize = matrix[0].size();
    int low = 0, high = rsize * csize - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / csize;
        int col = mid % csize;

        if (target == matrix[row][col])
        {
            return true;
        }
        else if (target > matrix[row][col])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    cout << searchMatrix(matrix, 3);

    return 0;
}