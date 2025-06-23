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

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* curr = head;
        while (curr) {
            int count = 0;
            ListNode* checker = head;

            // Count occurrences of curr->val in the whole list
            while (checker) {
                if (checker->val == curr->val) {
                    count++;
                }
                checker = checker->next;
            }

            // If value is unique, add to result
            if (count == 1) {
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};