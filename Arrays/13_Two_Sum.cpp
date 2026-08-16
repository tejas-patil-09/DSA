/*
Problem:
Find two elements whose sum equals the target.

Input:
A = {2, 6, 5, 8, 11}
Target = 14

Output:
6 8

Approach:
Store previously seen elements in a HashMap.
For each element, check whether target - a[i] already
exists.

TC: O(n)
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {2, 6, 5, 8, 11};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 14;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int required = target - a[i];

        if (mp.find(required) != mp.end()) {
            cout << required << " " << a[i] << endl;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "No pair found" << endl;

    return 0;
}