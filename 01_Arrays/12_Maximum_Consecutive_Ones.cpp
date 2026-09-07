/*
Problem:
Find the maximum number of consecutive 1s in a binary array.

Input:
{1, 1, 0, 1, 1, 1}

Output:
3

Approach:
Maintain the current consecutive-one count. Reset it when a zero appears
and update the maximum.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
A zero breaks the current consecutive sequence.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1};
    int n = 6;

    int count = 0, maximum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            maximum = max(maximum, count);
        }
        else {
            count = 0;
        }
    }

    cout << maximum;

    return 0;
}