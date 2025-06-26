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
        if(head->next==NULL && n==1) return NULL;
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;

        }
        int pos=len-n+1;
        if(pos==1){
            return head->next;

        }
        ListNode* prv=NULL;
        ListNode* curr=head;
        int i=1;
        while( i<pos){
            prv=curr;
            curr=curr->next;
            i++;

        }
        prv->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
        
    }
};