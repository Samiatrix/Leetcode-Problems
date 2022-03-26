class RandomizedSet {
public:
    unordered_map<int, int> valueToIndex;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valueToIndex.count(val)) return false;
        valueToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!valueToIndex.count(val))   return false;
        int lastVal = nums.back();
        int index = valueToIndex[val];
        nums[index] = lastVal;
        valueToIndex[lastVal] = index;
        valueToIndex.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */