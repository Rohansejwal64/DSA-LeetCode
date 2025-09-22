class KthLargest {
public:
 priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int K; // store the original k
    
    KthLargest(int k, vector<int>& nums) {
        K = k; // save k
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top(); // smallest in heap = Kth largest overall
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */