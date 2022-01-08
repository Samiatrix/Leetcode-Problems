class MyStack {
public:
    queue<int> q;
    int to;
    MyStack() {
        
    }
    
    void push(int x) {
        to = x;
        q.push(x);
        
        int s = q.size();
        while(s>1){
            int t = q.front();
            q.pop();
            q.push(t);
            s--;
        }
        
        cout<<q.front()<<endl;
    }
    
    int pop() {
        // int t = to;
        // cout<<q.front()<<" ";
        // q.pop();
        to = q.front();
        q.pop();
        // cout<<t<<" "<<to<<endl;
        return to;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */