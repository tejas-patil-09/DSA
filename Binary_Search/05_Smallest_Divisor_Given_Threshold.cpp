/*
==========================================================
      SMALLEST DIVISOR GIVEN A THRESHOLD
==========================================================

Problem:
Find the smallest divisor such that the sum of
ceil divisions is within the threshold.

Approach:
- Binary Search on divisor.
- Check whether the divisor satisfies the condition.

TC : O(n log(maxElement))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size(), maxV = 0;
    for (int i = 0; i < n; i++)
    {
        maxV = max(maxV, nums[i]);
    }
    int low = 1, high = maxV, ansV = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (nums[i] + mid - 1) / mid;
        }
        if (ans > threshold)
        {
            low = mid + 1;
        }
        else
        {
            ansV = mid;
            high = mid - 1;
        }
    }
    return ansV;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};

    cout << smallestDivisor(nums, 6);

    return 0;
}