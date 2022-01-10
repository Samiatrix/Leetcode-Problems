class MinStack {
public:
    vector<pair<int, int>> s;
    MinStack() {
    }
    
    void push(int val) {
        int m = s.empty() ? val : min(s.back().second, val);
        s.push_back({val, m});
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
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