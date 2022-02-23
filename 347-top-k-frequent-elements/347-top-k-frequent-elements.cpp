struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        
        for(auto i:mp){
            pq.push({i.second, i.first});
            if(pq.size() > k)  pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};