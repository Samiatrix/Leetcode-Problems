struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> freq;
        for(auto i:nums)    freq[i]++;
        for(auto i:freq)    pq.push({i.first, i.second});
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};