/*
Problem:
Find the row containing the maximum number of 1s.

Input:
0 0 1 1
0 1 1 1
0 0 0 1

Output:
Row 1

Approach:
Count the number of 1s in every row and keep track of the row with
the maximum count.

Time Complexity:
O(n × m)

Space Complexity:
O(1)

Key Insight:
Check each row independently and update the maximum whenever a larger
count is found.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][4] = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    int n = 3, m = 4;

    int row = -1;
    int maxOnes = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1)
                count++;
        }

        if (count > maxOnes) {
            maxOnes = count;
            row = i;
        }
    }

    cout << row;

    return 0;
}