#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = 5;

    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        maximum = max(maximum, arr[i]);
    }

    cout << maximum;

    return 0;
}