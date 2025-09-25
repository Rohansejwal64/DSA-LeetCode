class MyCircularQueue {
public:
int *arr;
int f,r;
int capa;
int s;
    MyCircularQueue(int k) {
        arr=new int[k];
        capa=k;
        s=0;
        f=0;
        r=-1;
        
    }
    
    bool enQueue(int value) {
        if(s==capa) return false;
        r=(r+1) % capa;
        arr[r]=value;
        s++;
        return true;
        
    }
    
    bool deQueue() {
        if(s==0) return false;
        f=(f+1) % capa;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
        
    }
    
    int Rear() {
        if(s==0) return -1;
        return arr[r];
        
    }
    
    bool isEmpty() {
        if(s==0) return true;
        return false;
        
    }
    
    bool isFull() {
        if(s==capa) return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */