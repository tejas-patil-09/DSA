/*
Problem:
Find all elements that are greater than every element
to their right.

Input:
10 22 12 3 0 6

Output:
22 12 6

Approach:
Traverse from right to left.
Maintain the maximum element seen so far.
An element is a leader if it is greater than this maximum.

TC: O(n)
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> leaders;

    int maximum = a[n - 1];
    leaders.push_back(maximum);

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > maximum) {
            leaders.push_back(a[i]);
            maximum = a[i];
        }
    }

    reverse(leaders.begin(), leaders.end());

    for (int x : leaders)
        cout << x << " ";

    cout << endl;

    return 0;
}