class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mp;
    int maxf = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxf = max(maxf, ++freq[x]);
        mp[freq[x]].push(x);
    }
    
    int pop() {
        int n = mp[maxf].top();
        mp[maxf].pop();
        if(!mp[freq[n]--].size()) maxf--;
        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */