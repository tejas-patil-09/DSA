/*
Problem:
Count the number of distinct elements in every window of size K.

Input:
{1,2,1,3,4,2,3}, K = 4

Output:
3 4 4 3

Approach:
Maintain a frequency map for the current window.
When the window moves, decrease the frequency of the outgoing element
and add the incoming element.

Time Complexity:
O(n) average

Space Complexity:
O(k)

Key Insight:
The map stores frequencies while count tracks the number of elements
whose frequency is currently greater than zero.
*/

int a[] = {1, 2, 1, 3, 4, 2, 3};
int n = 7, k = 4;

unordered_map<int, int> mp;
int count = 0;

for (int i = 0; i < n; i++) {

    if (i >= k) {

        mp[a[i - k]]--;
        count--;

        if (mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
    }

    mp[a[i]]++;

    if (mp[a[i]] == 1)
        count++;

    if (i >= k - 1)
        cout << count << " ";
}