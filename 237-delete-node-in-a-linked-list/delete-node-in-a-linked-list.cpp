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
   void deleteNode(ListNode* node) {
    node->val = node->next->val;        // Copy value from next node
    ListNode* temp = node->next;        // Save pointer to next node
    node->next = node->next->next;      // Skip the next node
    delete temp;                        // Free memory
}

};