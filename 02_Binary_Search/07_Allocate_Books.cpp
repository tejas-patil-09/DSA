/*
==========================================================
                ALLOCATE BOOKS
==========================================================

Problem:
Allocate books among students such that the
maximum pages assigned is minimized.

Approach:
- Binary Search on answer.
- Count students required.

TC : O(n log(sum))
SC : O(1)
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int allocateBooks(vector<int> &books, int students)
{
    int n = books.size();

    if (students > n)
        return -1;

    int maxV = INT_MIN, totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxV = max(maxV, books[i]);
        totalSum += books[i];
    }

    int low = maxV, high = totalSum;
    int ansVal = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int studentsRequired = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            pages += books[i];
            if (pages > mid)
            {
                studentsRequired++;
                pages = books[i];
            }
        }
        if (studentsRequired > students)
        {
            low = mid + 1;
        }
        else
        {
            ansVal = mid;
            high = mid - 1;
        }
    }
    return ansVal;
}

int main()
{
    vector<int> books = {12, 34, 67, 90};

    cout << allocateBooks(books, 2);

    return 0;
}