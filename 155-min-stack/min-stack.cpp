class MinStack {
public:
    stack<long long> st;
    long long minval;

    MinStack() {
        minval = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minval = val;
        }
        else if (val >= minval) {
            st.push(val);
        }
        else {
            st.push(2LL * val - minval); // encode
            minval = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        if (st.top() >= minval) {
            st.pop();
        }
        else {
            minval = 2LL * minval - st.top(); // decode
            st.pop();
        }
        
        if (st.empty()) minval = LLONG_MAX; // reset
    }
    
    int top() {
        if (st.empty()) return -1;
        long long topVal = st.top();
        if (topVal >= minval) return (int)topVal;
        else return (int)minval; // decoded
    }
    
    int getMin() {
        if (st.empty()) return -1; // safety
        return (int)minval;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */