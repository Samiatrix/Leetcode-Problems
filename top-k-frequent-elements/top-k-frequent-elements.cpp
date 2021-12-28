class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(auto i:mp){
            pq.push({i.second, i.first});
            if(pq.size()>(mp.size()-k)){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};