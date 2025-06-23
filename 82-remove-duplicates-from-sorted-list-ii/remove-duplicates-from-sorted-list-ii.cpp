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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        // Step 1: Count occurrences of each value
        std::unordered_map<int, int> freq;
        ListNode* temp = head;
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }

        // Step 2: Dummy node to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        temp = head;

        while (temp) {
            if (freq[temp->val] == 1) {
                // Keep the node (create a new one)
                tail->next = new ListNode(temp->val);
                tail = tail->next;
            }
            temp = temp->next;
        }

        // Optional: Clean up original list memory (if needed)
        // ...

        return dummy->next;
    }
};