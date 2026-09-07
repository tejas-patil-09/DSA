/*
Problem:
Calculate the amount of rainwater that can be trapped between bars.

Input:
{0,1,0,2,1,0,1,3,2,1,2,1}

Output:
6

Approach:
Use two pointers with leftMax and rightMax.
Process the side with the smaller height because its trapped water
is determined by the maximum on that side.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Water above a bar depends on the smaller of the maximum heights
from both sides.

Approach Used:
Optimal — Two Pointers
*/

int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
int n = 12;

int left = 0, right = n - 1;
int leftMax = 0, rightMax = 0;
int water = 0;

while (left <= right) {

    if (h[left] <= h[right]) {

        if (h[left] >= leftMax)
            leftMax = h[left];
        else
            water += leftMax - h[left];

        left++;
    }
    else {

        if (h[right] >= rightMax)
            rightMax = h[right];
        else
            water += rightMax - h[right];

        right--;
    }
}

cout << water;