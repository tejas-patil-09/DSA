/*
Problem:
Move all zeroes to the end while maintaining the relative order of
non-zero elements.

Input:
{0, 1, 0, 3, 12}

Output:
1 3 12 0 0

Approach:
Maintain a pointer j for the position where the next non-zero element
should be placed. Swap each non-zero element with arr[j].

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
The pointer j separates the processed non-zero portion from the rest.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = 5;

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}