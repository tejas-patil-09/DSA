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