/*
Problem:
Find the next lexicographically greater permutation
of the array.

Input:
1 2 3

Output:
1 3 2

Approach:
1. Find the first decreasing element from the right.
2. Find the smallest element greater than it from the right.
3. Swap them.
4. Reverse the remaining suffix.

If no decreasing element exists, reverse the entire array.

TC: O(n)
SC: O(1)

Revision:
Marked for future revision.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int index = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(a, a + n);
    } else {
        for (int i = n - 1; i > index; i--) {
            if (a[i] > a[index]) {
                swap(a[i], a[index]);
                break;
            }
        }

        reverse(a + index + 1, a + n);
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}
