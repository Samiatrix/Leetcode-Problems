class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    double med = 0.0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.size() == 0 && g.size() == 0){
            med = num;
            s.push(num);
            return;
        }
        else if(s.size()>g.size()){
            if(num<med){
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            else{
                g.push(num);
            }
            med = (g.top()+s.top())/2.0;
        }
        else if(s.size() == g.size()){
            if(num<med){
                s.push(num);
                med = s.top();;
            }
            else{
                g.push(num);
                med = g.top();
            }
        }
        else if(s.size()<g.size()){
            if(num>med){
                s.push(g.top());
                g.pop();
                g.push(num);
            }
            else{
                s.push(num);
            }
            med = (g.top()+s.top())/2.0;
        }        
    }
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */