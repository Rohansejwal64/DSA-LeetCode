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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* f=head;
        while(n){
            f=f->next;
            n--;
        }
        if(f==NULL){
            return head->next;
        }
        ListNode* s=head;
        while(f->next){
            s=s->next;
            f=f->next;

        }
        s->next=s->next->next;
        return head;
        
    }
};