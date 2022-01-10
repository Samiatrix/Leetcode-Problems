class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty() || s1.top()>=val)    s1.push(val);
        s2.push(val);
    }
    
    void pop() {
        int t = s2.top();
        s2.pop();
        
        if(s1.top() == t){
            s1.pop();
        }
    }
    
    int top() {
        return s2.top();
    }
    
    int getMin() {
        return s1.top();
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