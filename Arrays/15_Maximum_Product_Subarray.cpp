#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = 4;

    int prefix = 1, suffix = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (prefix == 0)
            prefix = 1;

        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }

    cout << ans;

    return 0;
}