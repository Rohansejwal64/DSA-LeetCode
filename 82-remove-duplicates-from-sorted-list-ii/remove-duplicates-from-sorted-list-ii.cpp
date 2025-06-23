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
         if (!head || !head->next) return head;

    // Dummy node to handle head duplicates
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;
    bool isDuplicate = false;

    while (curr) {
        
        // Skip all duplicates
        if (curr->next && curr->val == curr->next->val) {
            isDuplicate = true;
            ListNode* temp = curr;
            curr=curr->next;
            prev->next=curr;
            delete temp;
        }
        else{
            if(isDuplicate){
                 ListNode* temp = curr;
            curr=curr->next;
            prev->next=curr;
            delete temp;
            isDuplicate = false;


            }
            else{
                 prev = curr;
            curr = curr->next;

            }
        }

        
    }
    return dummy->next;
        
    }
};