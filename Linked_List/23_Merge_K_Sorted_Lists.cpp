/*
Problem:
Merge k sorted linked lists into one sorted linked list.

Input:
List 1: 1 -> 4 -> 5
List 2: 1 -> 3 -> 4
List 3: 2 -> 6

Output:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

Approach:

1. Brute:
   Traverse all k lists and store all node values.
   Sort the values and create/build the final list.

2. Optimal:
   Use a min-heap to store the current smallest node
   from each list.
   Remove the smallest node, attach it to the answer,
   then insert its next node into the heap.

Time Complexity:
O(n log k)

Space Complexity:
O(k)
*/

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        for(auto list : lists) {
            if(list)
                pq.push(list);
        }

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(tail->next)
                pq.push(tail->next);
        }

        return dummy.next;
    }
};