int MOD=1e4;
class StockSpanner {
public:
int *pge;
stack<int> st;
int *arr;
int size;
    StockSpanner() {
        pge=new int[MOD];
        arr=new int[MOD];
        size=0;
        
    }
    
    int next(int price) {
        while(!st.empty() && arr[st.top()] <=price) st.pop();
        if(st.empty()){
            pge[size]=-1;
        }
        else{
            pge[size]=st.top();
        }
        st.push(size);
        arr[size]=price;
        int ans=size+1-pge[size]-1;
        size++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */