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
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    cout << maxProfit;

    return 0;
}