/*
Problem:
Merge two sorted arrays into one sorted array.

Input:
A = {1, 3, 5, 7}
B = {2, 4, 6, 8}

Output:
1 2 3 4 5 6 7 8

Approach:

Version 1 — Extra Array:
Merge both arrays into a separate array using two pointers.

Version 2 — In-place from End:
Fill the first array from the back using three pointers.
This avoids overwriting elements that are still needed.

Version 3 — Gap Method:
Treat both arrays as one logical array.
Compare elements separated by a shrinking gap.

Time Complexity:
Version 1: O(n + m)
Version 2: O(n + m)
Version 3: O((n + m) log(n + m))

Space Complexity:
Version 1: O(n + m)
Version 2: O(1)
Version 3: O(1)

Key Insight:
For in-place merging, elements must be placed without overwriting
values that have not yet been processed.
*/


#include <bits/stdc++.h>
using namespace std;


/*
==================================================
Version 1 — Extra Array
==================================================
*/

void version1() {

    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};

    int n = 4, m = 4;

    int i = 0, j = 0;

    vector<int> ans;

    while (i < n && j < m) {

        if (a[i] < b[j])
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }

    while (i < n)
        ans.push_back(a[i++]);

    while (j < m)
        ans.push_back(b[j++]);

    for (int x : ans)
        cout << x << " ";

    cout << endl;
}


/*
Version 2 — In-place from End
*/

void version2() {

    int a[] = {1, 3, 5, 7, 0, 0, 0, 0};
    int b[] = {2, 4, 6, 8};

    int n = 4, m = 4;

    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;

    while (j >= 0) {

        if (i >= 0 && a[i] > b[j]) {

            a[k] = a[i];
            i--;
        }
        else {

            a[k] = b[j];
            j--;
        }

        k--;
    }

    for (int x : a)
        cout << x << " ";

    cout << endl;
}


/*
Version 3 — Gap Method
*/

void version3() {

    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};

    int n = 4, m = 4;

    int gap = (n + m + 1) / 2;

    while (gap > 0) {

        int i = 0;
        int j = gap;

        while (j < n + m) {

            if (i < n && j < n) {

                if (a[i] > a[j])
                    swap(a[i], a[j]);
            }

            else if (i < n && j >= n) {

                if (a[i] > b[j - n])
                    swap(a[i], b[j - n]);
            }

            else {

                if (b[i - n] > b[j - n])
                    swap(b[i - n], b[j - n]);
            }

            i++;
            j++;
        }

        if (gap == 1)
            break;

        gap = (gap + 1) / 2;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    for (int i = 0; i < m; i++)
        cout << b[i] << " ";

    cout << endl;
}


int main() {

    cout << "Version 1: ";
    version1();

    cout << "Version 2: ";
    version2();

    cout << "Version 3: ";
    version3();

    return 0;
}