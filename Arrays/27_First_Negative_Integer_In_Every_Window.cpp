/*
Problem:
Find the first negative integer in every window of size K.

Input:
{12,-1,-7,8,-15,30,16,28}, K = 3

Output:
-1 -1 -7 -15 -15 0

Approach:
Store the indices of negative elements in a queue.
For each completed window, remove expired indices.
The front of the queue is the first negative element.

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
The queue maintains negative elements in their original order.

Revision:
Marked for revision.
*/

int a[] = {12, -1, -7, 8, -15, 30, 16, 28};
int n = 8;
int k = 3;

queue<int> q;

for (int i = 0; i < n; i++) {

    if (a[i] < 0)
        q.push(i);

    if (i >= k - 1) {

        while (!q.empty() && q.front() <= i - k)
            q.pop();

        if (!q.empty())
            cout << a[q.front()] << " ";
        else
            cout << 0 << " ";
    }
}