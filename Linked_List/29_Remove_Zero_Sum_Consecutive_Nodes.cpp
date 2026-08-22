/*
Problem:
Remove all consecutive sequences of nodes whose sum is zero.

Input:
1 -> 2 -> -3 -> 3 -> 1

Output:
3 -> 1

Approach:

1. Brute:
   Try every starting node and keep calculating the sum
   of consecutive nodes. Whenever the sum becomes zero,
   remove that sequence.

2. Optimal:
   Use prefix sum + HashMap.
   If the same prefix sum appears at two different nodes,
   the nodes between them have sum zero.

   First pass:
   Store the latest node for every prefix sum.

   Second pass:
   Recalculate the prefix sum and skip the zero-sum
   sequence using the stored node.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> mp;
        int sum = 0;

        for (ListNode* temp = &dummy; temp; temp = temp->next) {
            sum += temp->val;
            mp[sum] = temp;
        }

        sum = 0;
        for (ListNode* temp = &dummy; temp; temp = temp->next) {
            sum += temp->val;
            temp->next = mp[sum]->next;
        }

        return dummy.next;
    }
};
