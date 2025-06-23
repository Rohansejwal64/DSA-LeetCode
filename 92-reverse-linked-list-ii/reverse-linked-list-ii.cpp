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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=1;
        ListNode *temp1=head;
        ListNode *temp2=head;
        while(temp1!=NULL && temp2!=NULL && count<=right){
            if(count<left-1){
                temp1=temp1->next;

            }
            temp2=temp2->next;
            count++;
        }
        ListNode *prv=temp1->next;
        if(left==1){
            prv=temp1;
        }
        ListNode *curr=prv->next;
        ListNode *forward=prv->next;
         while(forward!=temp2){
            forward=forward->next;
            curr->next=prv;
            prv=curr;
            curr=forward;
        }
         if(left==1){
        temp1->next=temp2;
        head=prv;
        }
        else{
        (temp1->next)->next=temp2;
        temp1->next=prv;
        }
     return head;
        }
};