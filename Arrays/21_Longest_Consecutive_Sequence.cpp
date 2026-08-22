/*
Problem:
Find the length of the longest sequence of consecutive
integers in an unsorted array.

Input:
100 4 200 1 3 2

Output:
4

Approach:
Store all elements in an unordered_set.
Start counting only when the previous number does not
exist. This identifies the beginning of a sequence.

TC: O(n) average
SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    int longest = 0;

    for (int x : st) {
        if (st.find(x - 1) == st.end()) {
            int current = x;
            int count = 1;

            while (st.find(current + 1) != st.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    cout << longest << endl;

    return 0;
}