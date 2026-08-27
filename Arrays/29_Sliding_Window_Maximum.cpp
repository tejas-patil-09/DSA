/*
Problem:
Find the maximum element in every window of size K.

Input:
{1,3,-1,-3,5,3,6,7}, K = 3

Output:
3 3 5 5 6 7

Approach:
Use a deque storing indices.
Remove indices outside the current window.
Remove smaller elements from the back because they cannot become
the maximum while the current larger element remains in the window.

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
The deque is maintained in decreasing order of values, so its front
always contains the maximum of the current window.
*/

int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
int n = 8, k = 3;

deque<int> q;

for (int i = 0; i < n; i++) {

    if (!q.empty() && q.front() == i - k)
        q.pop_front();

    while (!q.empty() && a[q.back()] <= a[i])
        q.pop_back();

    q.push_back(i);

    if (i >= k - 1)
        cout << a[q.front()] << " ";
}