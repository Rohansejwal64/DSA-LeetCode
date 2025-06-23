/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if (head == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Detect cycle using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected
            slow = head;

            // Phase 2: Find the starting node of the cycle
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next; // \U0001f501 Fix: move fast by 1 step, not 2
            }

            return slow;
        }
    }

    return NULL; // No cycle
}

};