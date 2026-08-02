/*
==========================================================
    CAPACITY TO SHIP PACKAGES WITHIN D DAYS
==========================================================

Problem:
Find the minimum ship capacity required to ship
all packages within the given number of days.

Approach:
- Binary Search on capacity.
- Count the days needed.

TC : O(n log(sum))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int maxV = INT_MIN, sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        maxV = max(maxV, weights[i]);
        sum += weights[i];
    }

    int low = maxV, high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int requiredDays = 1;
        int currentLoad = 0;
        for (int i = 0; i < n; i++)
        {
            if (currentLoad + weights[i] <= mid)
            {
                currentLoad += weights[i];
            }
            else
            {
                requiredDays++;
                currentLoad = weights[i];
            }
        }

        if (requiredDays > days)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << shipWithinDays(weights, 5);

    return 0;
}