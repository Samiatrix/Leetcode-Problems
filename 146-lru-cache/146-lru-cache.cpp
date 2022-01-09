class LRUCache {
public:
    int cap;
    // list<int> l;
    // unordered_map<int, int> mp;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key))  return -1;
        auto t = mp[key];
        l.splice(l.begin(), l, t);
        return t->second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto t = mp[key];
            l.splice(l.begin(), l, t);
            t->second = value;
            return;
        }
        if(cap == l.size()){
            int t = l.back().first;
            l.pop_back();
            mp.erase(t);
        }
        l.push_front({key, value});
        mp[key] = l.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */