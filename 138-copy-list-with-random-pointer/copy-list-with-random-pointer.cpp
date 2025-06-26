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
       if (!head) return nullptr;

    // Step 1: Interleave copied nodes
    Node* temp = head;
    while (temp) {
        Node* newnode = new Node(temp->val);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode->next;
    }

    // Step 2: Assign random pointers
    temp = head;
    while (temp) {
        if (temp->random) {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    // Step 3: Separate the two lists
    temp = head;
    Node* dummy = new Node(0);
    Node* copy = dummy;

    while (temp) {
        copy->next = temp->next;
        temp->next = temp->next->next;

        temp = temp->next;
        copy = copy->next;
    }

    return dummy->next;
    }
};