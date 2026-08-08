/*
Problem:
Return the node where the cycle begins.
If there is no cycle, return nullptr.

Input:
3 -> 2 -> 0 -> -4
     ^         |
     |_________|

Output:
Node with value 2

Approach:
1. Brute:
   Store visited node addresses in an unordered_set.
   The first node encountered again is the cycle start.

2. Optimal:
   Use Floyd's Cycle Detection Algorithm.

   Step 1:
   Move slow by one and fast by two until they meet.

   Step 2:
   Reset slow to head.

   Step 3:
   Move both one step at a time.
   The node where they meet is the start of the cycle.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
The first meeting point only proves that a cycle exists.
After resetting slow to head, moving both pointers at
the same speed makes them meet exactly at the cycle start.
==========================================================
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find meeting point
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (!fast || !fast->next)
            return nullptr;

        // Find start of cycle
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};