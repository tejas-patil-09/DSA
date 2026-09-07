/*
Problem:
Generate the first n rows of Pascal's Triangle.

Input:
n = 5

Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Approach:
Every row starts and ends with 1. Each inner element is the sum of the
two elements directly above it.

Time Complexity:
O(n²)

Space Complexity:
O(n²)

Key Insight:
Each element is formed from ans[i-1][j-1] + ans[i-1][j].
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    vector<vector<int>> ans(n);

    for (int i = 0; i < n; i++) {

        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;

        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    for (auto row : ans) {
        for (int x : row)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}