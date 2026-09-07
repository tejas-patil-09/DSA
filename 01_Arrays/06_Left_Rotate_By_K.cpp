/*
Problem:
Left rotate an array by K positions.

Input:
{1, 2, 3, 4, 5}, K = 2

Output:
3 4 5 1 2

Approach:
Use the reversal algorithm:
1. Reverse the first K elements.
2. Reverse the remaining elements.
3. Reverse the entire array.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Three reversals produce the required rotation in-place.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    k = k % n;

    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}