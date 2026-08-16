/*
Problem:
Find the union of two sorted arrays without duplicates.

Input:
A = {1, 2, 3, 4}
B = {2, 3, 5, 6}

Output:
1 2 3 4 5 6

Approach:
Use two pointers to compare elements of both arrays.
Add the smaller element and skip duplicates.

TC: O(n + m)
SC: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 5, 6};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    vector<int> ans;

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        } else {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }

    while (i < n) {
        if (ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }

    while (j < m) {
        if (ans.empty() || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}