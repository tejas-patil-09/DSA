/*
Problem:
Find the maximum sum of any contiguous subarray of size K.

Input:
{2,1,5,1,3,2}, K = 3

Output:
9

Approach:
Maintain a sliding window of size K.
Add the incoming element and remove the outgoing element
when the window moves.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
When the window moves by one position, only two elements change.
*/

int a[] = {2, 1, 5, 1, 3, 2};
int n = 6, k = 3;

int ans = 0;
int sum = 0;

for (int i = 0; i < n; i++) {

    sum += a[i];

    if (i >= k)
        sum -= a[i - k];

    if (i >= k - 1)
        ans = max(ans, sum);
}

cout << ans;