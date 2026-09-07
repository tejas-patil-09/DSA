/*
Problem:
Find the length of the longest substring containing at most k
distinct characters.

Input:
s = "eceba", k = 2

Output:
3

Approach:
Use a sliding window with a frequency map.
Expand the window using right.
When the number of distinct characters becomes greater than k,
shrink the window from the left.

Time Complexity:
O(n) average

Space Complexity:
O(k)

Key Insight:
Maintain a valid window containing at most k distinct characters.
*/

string s = "eceba";

int k = 2;
int n = s.length();

int left = 0;
int len = 0;

unordered_map<char, int> mp;

for (int right = 0; right < n; right++) {

    mp[s[right]]++;

    while (mp.size() > k) {

        mp[s[left]]--;

        if (mp[s[left]] == 0)
            mp.erase(s[left]);

        left++;
    }

    len = max(len, right - left + 1);
}

cout << "Max : " << len;