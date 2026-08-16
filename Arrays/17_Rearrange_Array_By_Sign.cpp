/*
Problem:
Rearrange the array so that positive and negative elements
appear alternately, starting with a positive element.

Input:
3 1 -2 -5 2 -4

Output:
3 -2 1 -5 2 -4

Approach:
Maintain separate positions for positive and negative
elements and place them directly in the result array.

TC: O(n)
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {3, 1, -2, -5, 2, -4};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> ans(n);

    int positive = 0;
    int negative = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            ans[positive] = a[i];
            positive += 2;
        } else {
            ans[negative] = a[i];
            negative += 2;
        }
    }

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}