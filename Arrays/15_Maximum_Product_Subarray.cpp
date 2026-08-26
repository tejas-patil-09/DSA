/*
Problem:
Find the maximum product of a contiguous subarray.

Input:
{2, 3, -2, 4}

Output:
6

Approach:
Maintain prefix and suffix products while traversing from both directions.
Reset a product to 1 whenever it becomes zero.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Negative values can turn a small product into the maximum product, so
checking from both directions handles sign changes.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = 4;

    int prefix = 1, suffix = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (prefix == 0)
            prefix = 1;

        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }

    cout << ans;

    return 0;
}