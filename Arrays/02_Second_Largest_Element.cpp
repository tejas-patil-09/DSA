/*
Problem:
Find the second largest distinct element in an array.

Input:
10 5 20 8 20

Output:
10

Approach:
Maintain the largest and second largest elements
while traversing the array.

TC: O(n)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {10, 5, 20, 8, 20};
    int n = sizeof(a) / sizeof(a[0]);

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] > secondLargest && a[i] != largest) {
            secondLargest = a[i];
        }
    }

    cout << secondLargest << endl;

    return 0;
}