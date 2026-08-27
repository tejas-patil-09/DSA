/*
Problem:
Find the length of the longest substring without repeating characters.

Input:
"pwwkew"

Output:
3

Approach:
Use a sliding window with left and right pointers.
Store the latest index of every character.
When a repeated character occurs inside the current window,
move left to one position after its previous occurrence.

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
Instead of shrinking the window one character at a time, jump left
directly to the position after the previous occurrence.

Revision:
Marked for revision.
*/

string s = "pwwkew";

int n = s.length();
int left = 0;
int ans = 0;

unordered_map<char, int> mp;

for (int right = 0; right < n; right++) {

    if (mp.find(s[right]) != mp.end() &&
        mp[s[right]] >= left) {

        left = mp[s[right]] + 1;
    }

    mp[s[right]] = right;

    ans = max(ans, right - left + 1);
}

cout << ans;