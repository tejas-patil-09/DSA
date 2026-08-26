/*
Problem:
Check whether an array is sorted in non-decreasing order.

Input:
{1, 2, 3, 4, 5}

Output:
true

Approach:
Compare every element with the previous element.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
A sorted array never has arr[i] < arr[i-1].
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    bool sorted = true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }

    cout << sorted;

    return 0;
}