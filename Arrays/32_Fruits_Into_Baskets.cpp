/*
Problem:
Find the longest contiguous subarray containing at most two distinct
types of fruits.

Input:
{1, 2, 3, 2, 2}

Output:
4

Approach:
Use a sliding window with a frequency map.
Expand the window using right.
If more than two distinct elements are present, shrink the window
from the left until it becomes valid again.

Time Complexity:
O(n) average

Space Complexity:
O(2)

Key Insight:
The problem is equivalent to finding the longest subarray with
at most two distinct elements.
*/

int fruit[] = {1, 2, 3, 2, 2};
int n = 5;

int left = 0;
int count = 0;

unordered_map<int, int> mp;

for (int right = 0; right < n; right++) {

    mp[fruit[right]]++;

    while (mp.size() > 2) {

        mp[fruit[left]]--;

        if (mp[fruit[left]] == 0)
            mp.erase(fruit[left]);

        left++;
    }

    count = max(count, right - left + 1);
}

cout << "Max : " << count;