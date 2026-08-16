/*
Problem:
Find the intersection of two sorted arrays.

Input:
A = {1, 2, 2, 3, 4}
B = {2, 2, 4, 6}

Output:
2 2 4

Approach:
Use two pointers.
If elements are equal, add the element and move both
pointers.
Otherwise move the pointer pointing to the smaller element.

TC: O(n + m)
SC: O(min(n, m))
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 2, 3, 4};
    int b[] = {2, 2, 4, 6};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    vector<int> ans;

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}