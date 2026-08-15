/*
Problem:
Remove duplicates from a sorted array in-place.

Input:
1 1 2 2 3 3

Output:
1 2 3

Approach:
Use two pointers.
j stores the position of the last unique element.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 1, 2, 2, 3, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
