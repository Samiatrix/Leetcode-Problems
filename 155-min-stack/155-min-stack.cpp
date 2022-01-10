class MinStack {
public:
    stack<pair<int, int>> s;
    int m;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())   m = val;
        else    m = min(s.top().second, val);
        s.push({val, m});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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