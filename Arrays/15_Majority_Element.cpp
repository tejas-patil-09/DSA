/*
Problem:
Find the element that appears more than n/2 times.

Input:
2 2 1 1 1 2 2

Output:
2

Approach:
Use Boyer-Moore Voting Algorithm.
Maintain a candidate and its count.
Different elements cancel each other.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = a[i];

        if (a[i] == candidate)
            count++;
        else
            count--;
    }

    cout << candidate << endl;

    return 0;
}