/*
Problem:
Find the element that appears more than n/2 times.

Input:
{2, 2, 1, 1, 1, 2, 2}

Output:
2

Approach:
Use Boyer-Moore Voting Algorithm to maintain a candidate and count.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Different elements cancel each other, while the majority element survives.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = 7;

    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate)
            count++;
        else
            count--;
    }

    cout << candidate;

    return 0;
}