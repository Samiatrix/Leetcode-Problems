struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(auto i:mp)  pq.push({i.first, i.second});
        
        vector<int> ans;
        
        while(!pq.empty() && k--){
            pair<int, int> curr = pq.top();
            pq.pop();
            ans.push_back(curr.first);
        }
        return ans;
    }
};