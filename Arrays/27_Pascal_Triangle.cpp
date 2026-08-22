/*
Problem:
Generate Pascal's Triangle for a given number of rows.

Input:
5

Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Approach:
Each element is formed using the two elements directly
above it.

TC: O(n^2)
SC: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    vector<vector<int>> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i].resize(i + 1, 1);

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