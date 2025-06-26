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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode* prv=NULL;
        ListNode* curr=head;
        int pos =1;
        ListNode* fe=NULL;
        ListNode* le=NULL;
        while(curr){
            if(pos%2==0){
                if(fe==NULL){
                    fe=curr;
                    le=curr;
                }
                else{
                    le->next=curr;
                    le=curr;
                }
                prv->next=curr->next;
                curr=curr->next;
            }
            else{
                prv=curr;
                curr=curr->next;
            }
            pos++;
        }
        prv->next=fe;
        le->next=NULL;
        return head;
        
    }
};