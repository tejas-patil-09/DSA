/*
Problem:
Find the smallest substring of s that contains all characters of t,
including their required frequencies.

Input:
s = "ADOBECODEBANC"
t = "ABC"

Output:
"BANC"

Approach:
Store the required frequency of every character of t.
Expand the window using right.
When the window contains all required characters, shrink it from
the left while keeping it valid.
Track the smallest valid window and its starting position.

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
cnt represents how many required characters have been matched.
The window is valid when cnt == t.length().

Revision:
The implementation was worked through carefully and should be revised.
*/

string s = "ADOBECODEBANC";
string t = "ABC";

int n = s.length();

int left = 0;
int cnt = 0;
int len = INT_MAX;
int start = -1;

unordered_map<char, int> mp1;

for (int i = 0; i < t.length(); i++)
    mp1[t[i]]++;

for (int right = 0; right < n; right++) {

    if (mp1.find(s[right]) != mp1.end()) {

        if (mp1[s[right]] > 0)
            cnt++;

        mp1[s[right]]--;
    }

    while (cnt == t.length()) {

        if (right - left + 1 < len) {

            len = right - left + 1;
            start = left;
        }

        if (mp1.find(s[left]) != mp1.end()) {

            mp1[s[left]]++;

            if (mp1[s[left]] > 0)
                cnt++;
        }

        left++;
    }
}

if (start == -1)
    cout << "";
else
    cout << s.substr(start, len);