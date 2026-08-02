/*
==========================================================
                 BINARY SEARCH BASICS
==========================================================

Contents
1. Standard Binary Search
2. Lower Bound
3. Upper Bound
4. Search Insert Position
5. Floor
6. Ceil
7. First Occurrence
8. Last Occurrence
9. Count Occurrences

Note:
- All functions assume the input array is sorted
  in ascending order.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

//==========================================================
// 1. Standard Binary Search
// TC : O(log n)
// SC : O(1)
// Returns the index of target, or -1 if not found.
//==========================================================

int binarySearch(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

//==========================================================
// 2. Lower Bound
// TC : O(log n)
// SC : O(1)
// Returns the first index with value >= target.
//==========================================================

int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//==========================================================
// 3. Upper Bound
// TC : O(log n)
// SC : O(1)
// Returns the first index with value > target.
//==========================================================

int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//==========================================================
// 4. Search Insert Position
// TC : O(log n)
// SC : O(1)
// Returns the index where target should be inserted.
//==========================================================

int searchInsertPosition(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//==========================================================
// 5. Floor
// TC : O(log n)
// SC : O(1)
// Returns the index of the greatest element <= target.
//==========================================================

int floorElement(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

//==========================================================
// 6. Ceil
// TC : O(log n)
// SC : O(1)
// Returns the index of the smallest element >= target.
//==========================================================

int ceilElement(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

//==========================================================
// 7. First Occurrence
// TC : O(log n)
// SC : O(1)
// Returns the first occurrence index of target.
//==========================================================

int firstOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

//==========================================================
// 8. Last Occurrence
// TC : O(log n)
// SC : O(1)
// Returns the last occurrence index of target.
//==========================================================

int lastOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

//==========================================================
// 9. Count Occurrences
// TC : O(log n)
// SC : O(1)
// Returns the total number of occurrences of target.
//==========================================================

int countOccurrences(vector<int> &arr, int target)
{
    int first = firstOccurrence(arr, target);

    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, target);

    return last - first + 1;
}

//==========================================================
// Demo
//==========================================================

int main()
{
    vector<int> arr = {2, 4, 4, 4, 7, 9};

    cout << "Binary Search: " << binarySearch(arr, 7) << endl;
    cout << "Lower Bound: " << lowerBound(arr, 5) << endl;
    cout << "Upper Bound: " << upperBound(arr, 4) << endl;
    cout << "Search Insert: " << searchInsertPosition(arr, 6) << endl;
    cout << "Floor: " << floorElement(arr, 6) << endl;
    cout << "Ceil: " << ceilElement(arr, 6) << endl;
    cout << "First Occurrence: " << firstOccurrence(arr, 4) << endl;
    cout << "Last Occurrence: " << lastOccurrence(arr, 4) << endl;
    cout << "Count Occurrences: " << countOccurrences(arr, 4) << endl;

    return 0;
}
