#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = 5;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    cout << ans;

    return 0;
}