#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = 5, target = 8;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}