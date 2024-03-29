class KthLargest {
public:
    int cap;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size() > cap) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > cap) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */