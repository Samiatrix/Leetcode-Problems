class LFUCache {
public:
    unordered_map<int, pair<int, int>> keyValueFreq;
    unordered_map<int, list<int>>freqToKey;
    unordered_map<int, list<int>::iterator> keyListit;
    int cap;
    int minf;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!keyValueFreq.count(key))    return -1;
        //remove old
        auto curr = keyValueFreq[key];
        int f = curr.second;
        auto it = keyListit[key];
        freqToKey[f].erase(it);
        keyListit.erase(key);
        f++;
        //again add
        freqToKey[f].push_front(key);
        keyListit[key] = freqToKey[f].begin();
        keyValueFreq[key].second = f;
        if(freqToKey[minf].empty())    minf = f;
        return curr.first;
    }
    
    void put(int key, int value) {
        
        if(cap<=0)  return;
        if(get(key)!=-1){
            keyValueFreq[key].first = value;
            return;
        }
        // cout<<"keyvaluemap check done"<<endl;
        if(keyValueFreq.size() == cap){
            int k = freqToKey[minf].back();
            keyValueFreq.erase(k);
            freqToKey[minf].pop_back();
            keyListit.erase(k);
            
        }
        
        minf = 1;
        keyValueFreq[key] = {value, minf};
        freqToKey[minf].push_front(key);
        keyListit[key] = freqToKey[minf].begin();
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */