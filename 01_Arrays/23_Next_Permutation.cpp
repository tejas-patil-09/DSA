/*
Problem:
Find the next lexicographically greater permutation.

Input:
{1,2,3}

Output:
{1,3,2}

Approach:
1. Find the first decreasing element from the right.
2. Find the smallest element greater than it from the right.
3. Swap them.
4. Reverse the suffix.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
The suffix is already in decreasing order, so reversing it after
the swap produces the smallest possible next permutation.

Revision:
Marked for revision.
*/

vector<int> nums = {1, 2, 3};

int n = nums.size();
int i = n - 2;

while (i >= 0 && nums[i] >= nums[i + 1])
    i--;

if (i >= 0) {

    int j = n - 1;

    while (nums[j] <= nums[i])
        j--;

    swap(nums[i], nums[j]);
}

reverse(nums.begin() + i + 1, nums.end());

for (int x : nums)
    cout << x << " ";