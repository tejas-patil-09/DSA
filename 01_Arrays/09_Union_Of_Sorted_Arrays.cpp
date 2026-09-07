/*
Problem:
Find the union of two sorted arrays without duplicate elements.

Input:
A = {1, 2, 3, 4}
B = {2, 3, 5, 6}

Output:
1 2 3 4 5 6

Approach:
Use two pointers to traverse both sorted arrays and add the smaller
element. When both are equal, add it once and move both pointers.

Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

Key Insight:
Sorted order allows both arrays to be merged while removing duplicates.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 5, 6};

    int n = 4, m = 4;
    int i = 0, j = 0;

    vector<int> ans;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i]) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        else {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
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

    return 0;
}