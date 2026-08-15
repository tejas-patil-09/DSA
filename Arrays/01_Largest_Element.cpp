/*
Problem:
Find the largest element in an array.

Input:
10 5 20 8

Output:
20

Approach:
Traverse the array and keep track of the maximum element.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {10, 5, 20, 8};
    int n = sizeof(a) / sizeof(a[0]);

    int maximum = a[0];

    for (int i = 1; i < n; i++) {
        maximum = max(maximum, a[i]);
    }

    cout << maximum << endl;

    return 0;
}