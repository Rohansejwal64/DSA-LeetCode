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
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    // Dummy node to handle edge cases cleanly
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevGroupEnd = dummy;
    ListNode* curr = head;

    while (true) {
        // Check if there are at least k nodes left
        ListNode* check = curr;
        for (int i = 0; i < k; ++i) {
            if (!check) {
                
                return dummy->next;
            }
            check = check->next;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* tail = curr;
        for (int i = 0; i < k; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect previous group with reversed group
        prevGroupEnd->next = prev;
        tail->next = curr;

        // Move prevGroupEnd to the end of the reversed group
        prevGroupEnd = tail;
    }

    // Should not reach here
    return dummy->next;
}

};