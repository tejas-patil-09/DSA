/*
==========================================================
     FIND MINIMUM IN ROTATED SORTED ARRAY
==========================================================

Problem:
Find the minimum element in a rotated sorted array.

Approach:
- Apply Binary Search.
- Compare middle element with the last element.
- Narrow the search space.

TC : O(log n)
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int minV = INT_MAX;
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        if (nums[low] <= nums[high])
        {
            minV = min(minV, nums[low]);
            break;
        }

        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid])
        {
            minV = min(minV, nums[low]);
            low = mid + 1;
        }
        else
        {
            minV = min(minV, nums[mid]);
            high = mid - 1;
        }
    }
    return minV;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << findMin(nums);

    return 0;
}