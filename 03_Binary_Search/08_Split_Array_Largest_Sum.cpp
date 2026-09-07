/*
==========================================================
            SPLIT ARRAY LARGEST SUM
==========================================================

Problem:
Split the array into k subarrays while minimizing
the largest subarray sum.

Approach:
- Binary Search on answer.
- Count partitions required.

TC : O(n log(sum))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
        return -1;

    int maxV = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxV = max(maxV, nums[i]);
    }

    int low = maxV, high = sum;
    int ansVal = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int currentSum = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (currentSum > mid)
            {
                count++;
                currentSum = nums[i];
            }
            else
            {
                currentSum += nums[i];
            }
        }
        if (count > k)
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
    vector<int> nums = {7, 2, 5, 10, 8};

    cout << splitArray(nums, 2);

    return 0;
}