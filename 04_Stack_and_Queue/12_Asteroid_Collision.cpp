/*
Problem:
Given an array of asteroids moving in a line, positive values
move right and negative values move left.
When two asteroids collide, the smaller one explodes.
If they have equal sizes, both explode.

Input:
An integer array asteroids.

Output:
The state of the asteroids after all collisions.

Approach:
1. Brute:
   Repeatedly find colliding asteroids and remove the smaller
   one until no collision remains.
   Time Complexity: O(n^2)

2. Optimal:
   Use a stack.
   A collision is possible only when the stack top is moving
   right and the current asteroid is moving left.
   Continue resolving collisions until the current asteroid
   is destroyed or no collision is possible.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Only opposite-moving asteroids can collide, and every asteroid
is pushed and popped at most once.
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (alive && asteroid < 0 &&
                   !st.empty() && st.back() > 0) {

                if (st.back() < -asteroid) {
                    st.pop_back();
                }
                else if (st.back() == -asteroid) {
                    st.pop_back();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};