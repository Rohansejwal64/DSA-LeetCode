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
    ListNode* reverseList(ListNode* head) {
         ListNode* prev = nullptr;
    while (head != nullptr) {
        ListNode* nextNode = head->next; // store next
        head->next = prev;               // reverse pointer
        prev = head;                     // move prev forward
        head = nextNode;                 // move head forward
    }
    return prev;
        
    }
};