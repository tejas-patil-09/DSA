/*
Problem:
Split a linked list into k consecutive parts.
The parts should be as equal in size as possible.
If the nodes cannot be divided equally, the earlier
parts should contain one extra node.

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
k = 3

Output:
[1 -> 2 -> 3]
[4 -> 5]
[6 -> 7]

Approach:

1. Find the total length of the linked list.

2. Calculate:
   base = length / k
   extra = length % k

   Every part gets 'base' nodes.
   The first 'extra' parts get one additional node.

3. For each part:
   Decide exactly how many nodes it should contain.
   Take exactly those nodes.
   Cut the list after that part.

Key Insight:
First decide exactly how many nodes this part should contain
-> take exactly that many nodes
-> cut the list.

Time Complexity:
O(n)

Space Complexity:
O(k) for the output vector.
O(1) auxiliary space.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        int length = 0;
        for (ListNode* temp = head; temp; temp = temp->next)
            length++;

        int base = length / k;
        int extra = length % k;
        ListNode* temp = head;

        for (int part = 0; part < k; part++) {
            int partSize = base + (extra > 0);
            if (extra > 0)
                extra--;

            if (partSize == 0) {
                ans.push_back(nullptr);
                continue;
            }

            ListNode* partHead = temp;
            ListNode* prev = nullptr;

            for (int i = 0; i < partSize; i++) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;
            ans.push_back(partHead);
        }

        return ans;
    }
};
