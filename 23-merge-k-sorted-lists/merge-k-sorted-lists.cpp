/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class compare {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap based on node values
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if (temp->next)
                pq.push(temp->next);
            tail->next = temp;
            tail = tail->next;
        }
        return dummy->next;
    }
};