/*
Problem:
Determine whether a linked list contains a cycle.

Input:
3 -> 2 -> 0 -> -4
     ^         |
     |_________|

Output:
true

Approach:
1. Brute:
   Store visited node addresses in an unordered_set.
   If a node is encountered again, a cycle exists.

2. Optimal:
   Use Floyd's Cycle Detection Algorithm.
   Slow moves one step and fast moves two steps.
   If they meet, a cycle exists.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
In a cycle, the faster pointer will eventually catch
the slower pointer.
==========================================================
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
