class LFUCache {
public:
    unordered_map<int, pair<int, int>> keyValueFreq;
    unordered_map<int, list<int>> freqKey;
    unordered_map<int, list<int>::iterator> keylistit;
    int minf;
    int cap;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!keyValueFreq.count(key)) return -1;
        auto curr = keyValueFreq[key];
        int f = curr.second;
        auto it = keylistit[key];
        freqKey[f++].erase(it);
        keylistit.erase(key);
        freqKey[f].push_front(key);
        keylistit[key] = freqKey[f].begin();
        keyValueFreq[key].second = f;
        if(freqKey[minf].empty())    minf = f;
        return curr.first;
    }
    
    void put(int key, int value) {
        if(cap<=0)  return ;
        if(get(key)!=-1){
            keyValueFreq[key].first = value;
            return ;
        }
        if(keyValueFreq.size() == cap){
            int k = freqKey[minf].back();
            freqKey[minf].pop_back();
            keylistit.erase(k);
            keyValueFreq.erase(k);
        }
        // cout<<"checks done"<<endl;
        minf = 1;
        keyValueFreq[key] = {value, minf};
        freqKey[minf].push_front(key);
        keylistit[key] = freqKey[minf].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */