class LFUCache {
public:
    unordered_map<int, pair<int, int>> keyvaluefreq;
    unordered_map<int, list<int>::iterator> keytolist;
    unordered_map<int, list<int>> freq;
    int cap;
    bool capa;
    int minf;
    LFUCache(int capacity) {
        cap = capacity;
        if(cap) capa = true;
        else    capa = false;
    }
    
    int get(int key) {
        if(!keyvaluefreq.count(key)){
            return -1;
        }
        auto t = keyvaluefreq[key];
        int f = t.second;
        freq[f].erase(keytolist[key]);
        f++;
        keytolist.erase(key);
        freq[f].push_front(key);
        keytolist[key] = freq[f].begin();
        
        keyvaluefreq[key].second = f;
        
        if(freq[minf].empty())  minf = f;
        return keyvaluefreq[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0)   return;
        if(get(key)!=-1){
            keyvaluefreq[key].first = value;
            return;
        }
        if(keyvaluefreq.size() == cap){
            int k = freq[minf].back();
            freq[minf].pop_back();
            keyvaluefreq.erase(k);
            keytolist.erase(k);
        }
        minf = 1;
        keyvaluefreq[key] = {value, minf};
        freq[minf].push_front(key);
        keytolist[key] = freq[minf].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */