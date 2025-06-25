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
ListNode* getmid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* prv=NULL;
    ListNode* curr=head;
    ListNode* forwd=head;
    while(forwd!=NULL){
        forwd=forwd->next;
        curr->next=prv;
        prv=curr;
        curr=forwd;
    }
    return prv;
}

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* middle=getmid(head);
        middle->next=reverse(middle->next);
        ListNode* temp=middle->next;
        ListNode* temp2=head;
        while(temp!=NULL){
            if(temp2->val != temp->val){
                return false;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
         middle->next=reverse(middle->next);
         return true;

        
    }
};