/*
==========================================================
              PAINTER'S PARTITION
==========================================================

Problem:
Assign boards to painters such that the maximum
time taken is minimized.

Approach:
- Binary Search on answer.
- Count painters required.

TC : O(n log(sum))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int paintersPartition(vector<int> &boards, int painters)
{
    int n = boards.size();
    if (painters > n)
        return -1;

    int sum = 0, maxV = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        maxV = max(maxV, boards[i]);
    }

    int low = maxV, high = sum, ansVal = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 1;
        int currentSum = 0;
        for (int i = 0; i < n; i++)
        {
            currentSum += boards[i];
            if (currentSum > mid)
            {
                count++;
                currentSum = boards[i];
            }
        }

        if (count > painters)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ansVal = mid;
        }
    }
    return ansVal;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};

    cout << paintersPartition(boards, 2);

    return 0;
}