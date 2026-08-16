/*
Problem:
Find the length of the longest subarray with sum K.

Input:
A = {1, 2, 3, 1, 1, 1, 1}
K = 3

Output:
3

Approach:
Maintain prefix sum and store the first occurrence of
each prefix sum in a HashMap.

If prefixSum - K exists, the subarray between that index
and the current index has sum K.

TC: O(n)
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 1, 1, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    unordered_map<int, int> mp;

    int sum = 0;
    int maximum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (sum == k)
            maximum = i + 1;

        if (mp.find(sum - k) != mp.end()) {
            maximum = max(maximum, i - mp[sum - k]);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    cout << maximum << endl;

    return 0;
}