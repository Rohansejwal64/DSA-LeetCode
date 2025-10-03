class Node{
    public:
    int val;
    int k;
    Node* next;
    Node* prv;
    Node(int key,int value){
        next=prv=NULL;
        val=value;
        k=key;
    }

};
class LRUCache {
public:
Node * head;
Node * tail;
int size;
unordered_map<int,Node*> mp;
int capa;


    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prv=head;
        size=0;
        capa=capacity;


        
    }
    
    int get(int key) {
        if(mp.find(key) !=mp.end()){
            Node* temp=mp[key];
            temp->prv->next=temp->next;
            temp->next->prv=temp->prv;
            temp->prv=head;
            temp->next=head->next;
            head->next=temp;
            temp->next->prv=temp;
            return temp->val;
        


        }
        else{
            return -1;
        }

        
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(size==capa){
                Node *temp=tail->prv;
                temp->prv->next=tail;
                tail->prv=temp->prv;
                mp.erase(temp->k);
                delete temp;
                size--;
            }
            Node *newnode=new Node(key,value);
            newnode->prv=head;
            newnode->next=head->next;
            head->next=newnode;
            newnode->next->prv=newnode;
            mp[key]=newnode;
            size++;


        }
        else{
            Node* temp=mp[key];
            temp->val=value;
            temp->prv->next=temp->next;
            temp->next->prv=temp->prv;
            temp->prv=head;
            temp->next=head->next;
            head->next=temp;
            temp->next->prv=temp;

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */