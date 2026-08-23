#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 0, 1};
    int n = 3;

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        ans ^= i;
    }

    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    cout << ans;

    return 0;
}