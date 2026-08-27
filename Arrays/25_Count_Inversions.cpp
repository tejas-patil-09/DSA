/*
Problem:
Count pairs (i,j) such that i < j and arr[i] > arr[j].

Input:
{5,3,2,4,1}

Output:
7

Approach:
Brute force:
Check every possible pair and count the pairs satisfying
arr[i] > arr[j].

Time Complexity:
O(n²)

Space Complexity:
O(1)

Key Insight:
An inversion occurs when a larger element appears before a smaller element.

*/

int arr[] = {5, 3, 2, 4, 1};
int n = 5;

int count = 0;

for (int i = 0; i < n - 1; i++) {

    for (int j = i + 1; j < n; j++) {

        if (arr[i] > arr[j])
            count++;
    }
}

cout << count;