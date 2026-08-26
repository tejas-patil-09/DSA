/*
Problem:
Merge all overlapping intervals.

Input:
{1,3}, {2,6}, {8,10}, {15,18}

Output:
{1,6}, {8,10}, {15,18}

Approach:
Sort intervals by starting point. Compare each interval with the last
merged interval. Merge when they overlap.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Key Insight:
After sorting, only the last merged interval needs to be checked.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (auto interval : intervals) {

        if (ans.empty() || ans.back()[1] < interval[0]) {
            ans.push_back(interval);
        }
        else {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    for (auto x : ans) {
        cout << x[0] << " " << x[1] << endl;
    }
}