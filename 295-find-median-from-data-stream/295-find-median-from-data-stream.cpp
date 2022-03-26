class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            if(median > num){
                maxHeap.push(num);
                median = maxHeap.top();
            }
            else{
                minHeap.push(num);
                median = minHeap.top();
            }
        }
        else if(maxHeap.size() > minHeap.size()){
            if(median > num){
                maxHeap.push(num);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else{
                minHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        else if(maxHeap.size() < minHeap.size()){
            if(median > num){
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
    }
    
    double findMedian() {
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */