/*
Problem:
Remove duplicates from a sorted array in-place.

Input:
{1, 1, 2, 2, 3, 4, 4}

Output:
1 2 3 4

Approach:
Use two pointers. Keep j at the last unique element and place the next
unique element at j+1.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Because the array is sorted, duplicates are adjacent.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = 7;

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}