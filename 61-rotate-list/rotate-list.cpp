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
ListNode* rev(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;


}

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
         int len = 0;
    ListNode* tempCount = head;
    while (tempCount) {
        len++;
        tempCount = tempCount->next;
    }

    // Step 2: Optimize k
    k = k % len;
    if (k == 0) return head; // No rotation needed
        ListNode* h2=rev(head);
        ListNode* h1=head;
        ListNode* temp=h2;
        for(int i=0;i<k;i++){
            h1->next=temp;
            h2=h2->next;
            temp->next=NULL;
            h1=temp;
            temp=h2;

        }
        return rev(h2);

        
    }
};