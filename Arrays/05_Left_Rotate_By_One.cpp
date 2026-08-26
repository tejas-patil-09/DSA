/*
Problem:
Left rotate an array by one position.

Input:
{1, 2, 3, 4, 5}

Output:
2 3 4 5 1

Approach:
Store the first element, shift all remaining elements one position left,
then place the stored element at the end.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Only the first element needs to be temporarily stored.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int temp = arr[0];

    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}