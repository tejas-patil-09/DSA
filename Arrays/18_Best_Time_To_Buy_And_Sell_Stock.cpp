/*
Problem:
Find the maximum profit from buying and selling a stock
once.

Input:
7 1 5 3 6 4

Output:
5

Approach:
Maintain the minimum price seen so far.
For each price, calculate the profit obtained by selling
at the current price.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int minimum = prices[0];
    int maximumProfit = 0;

    for (int i = 1; i < n; i++) {
        maximumProfit = max(maximumProfit, prices[i] - minimum);
        minimum = min(minimum, prices[i]);
    }

    cout << maximumProfit << endl;

    return 0;
}