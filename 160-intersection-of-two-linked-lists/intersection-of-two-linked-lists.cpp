/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
        ListNode* temp=headA;
        int len1=0;
        while(temp){
            len1++;
            temp=temp->next;
        }
        temp=headB;
        int len2=0;
        while(temp){
            len2++;
            temp=temp->next;
        }
        int pos=abs(len1-len2);
        if(len1>len2){
            while(pos){
                headA=headA->next;
                pos--;
            }

        }
        else{
            while(pos){
                headB=headB->next;
                pos--;
            }

        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }


       
        return NULL;

        
    }
};