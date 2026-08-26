/*
Problem:
Find the second largest distinct element in an array.

Input:
{5, 3, 8, 1, 9}

Output:
8

Approach:
Maintain largest and secondLargest while traversing the array.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
When a new largest is found, the previous largest becomes second largest.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = 5;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << secondLargest;

    return 0;
}