/*
Problem:
Find the length of the longest substring that can be made to contain
the same character by replacing at most k characters.

Input:
s = "AABABBA", k = 1

Output:
4

Approach:
Use a sliding window.
Maintain the frequency of characters in the current window and the
maximum frequency of any single character.

A window is valid if:

window size - maximum frequency <= k

If the window becomes invalid, shrink it from the left.

Time Complexity:
O(n)

Space Complexity:
O(26)

Key Insight:
We only need to know the most frequent character in the window.
The remaining characters are the ones that need to be replaced.
*/

string s = "AABABBA";
int k = 1, n = s.length(), len = 0;

int freq = 0;
unordered_map<char, int> mp;

int left = 0;

for (int right = 0; right < n; right++) {

    mp[s[right]]++;

    freq = max(freq, mp[s[right]]);

    while ((right - left + 1) - freq > k) {

        mp[s[left]]--;
        left++;
    }

    len = max(len, right - left + 1);
}

cout << "Max : " << len;