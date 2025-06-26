/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        unordered_map<Node*,Node*> mpp;
        Node* dummy=new Node(0);
        Node* copy=dummy;
        Node* temp=head;
        while(temp){
            Node* newnode=new Node(temp->val);
            copy->next=newnode;
            copy=newnode;
            mpp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        copy=dummy->next;
        while(temp){
            if(temp->random!=NULL){
                copy->random=mpp[temp->random];
            }
            temp=temp->next;
            copy=copy->next;
        }
        return dummy->next;
        
    }
};