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