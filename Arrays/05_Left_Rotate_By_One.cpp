/*
Problem:
Left rotate an array by one position.

Input:
1 2 3 4 5

Output:
2 3 4 5 1

Approach:
Store the first element.
Shift the remaining elements one position left.
Place the first element at the end.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int first = a[0];

    for (int i = 1; i < n; i++) {
        a[i - 1] = a[i];
    }

    a[n - 1] = first;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}