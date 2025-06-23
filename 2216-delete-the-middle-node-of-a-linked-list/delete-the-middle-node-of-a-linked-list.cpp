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
    if (head == NULL || head->next == NULL) {
        // Don't delete here; let the caller/test system handle it
        return NULL;
    }

    int len = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    int pos = len / 2;

    ListNode* prev = NULL;
    ListNode* curr = head;
    for (int i = 0; i < pos; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    // Optional: only if you manage memory manually
    // delete curr;

    return head;
}

};