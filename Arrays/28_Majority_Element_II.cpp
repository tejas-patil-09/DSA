/*
Problem:
Find all elements that appear more than n/3 times in an array.

Input:
1 1 1 3 3 2 2 2

Output:
1 2

Approach:
At most two elements can appear more than n/3 times.
Use the extended Boyer-Moore Voting Algorithm to find
two candidates, then verify their frequencies.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == candidate1) {
            count1++;
        }
        else if (a[i] == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = a[i];
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = a[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == candidate1)
            count1++;

        if (a[i] == candidate2)
            count2++;
    }

    if (count1 > n / 3)
        cout << candidate1 << " ";

    if (candidate2 != candidate1 && count2 > n / 3)
        cout << candidate2 << " ";

    cout << endl;

    return 0;
}