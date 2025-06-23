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
  ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;  // Only one node, return NULL

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    prev->next = slow->next;

    // Optional: delete slow if managing memory manually
    // delete slow;

    return head;
}


};