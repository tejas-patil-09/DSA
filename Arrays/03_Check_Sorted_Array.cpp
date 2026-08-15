/*
Problem:
Check whether an array is sorted in non-decreasing order.

Input:
1 2 3 4 5

Output:
Sorted

Approach:
Compare every element with the previous element.
If a[i] < a[i - 1], the array is not sorted.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    bool sorted = true;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted)
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;

    return 0;
}