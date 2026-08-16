/*
Problem:
Sort an array containing only 0, 1 and 2.

Input:
0 2 1 2 0 1

Output:
0 0 1 1 2 2

Approach:
Use the Dutch National Flag algorithm.

Maintain:
low   -> position for 0
mid   -> current element
high  -> position for 2

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {0, 2, 1, 2, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1) {
            mid++;
        }
        else {
            swap(a[mid], a[high]);
            high--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}