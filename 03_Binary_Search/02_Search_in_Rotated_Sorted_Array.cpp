/*
==========================================================
        SEARCH IN ROTATED SORTED ARRAY
==========================================================

Problem:
Given a rotated sorted array and a target value,
return its index if found, otherwise return -1.

Approach:
- Use Binary Search.
- Check which half is sorted.
- Eliminate one half in every iteration.

TC : O(log n)
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << search(nums, 0) << endl;
    cout << search(nums, 3) << endl;

    return 0;
}