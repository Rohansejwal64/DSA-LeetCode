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
        if(head==NULL){
            return NULL;
        }
        int cnt=1;
         ListNode *temp=head;
        while(cnt<k && temp!=NULL){
            temp=temp->next;
            cnt++;
             }
             if(temp==NULL){
                return head;
             }
        
        int count =1;
         ListNode *prv=NULL;
        ListNode *curr=head;
        ListNode *nextnode=head;
        while(nextnode!=NULL && count<=k){
            nextnode=nextnode->next;
            curr->next=prv;
            prv=curr;
            curr=nextnode;
            count++;

        }
        head->next=reverseKGroup(curr,k);
        return prv;
        
    }
};