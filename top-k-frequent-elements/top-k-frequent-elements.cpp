struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto i:mp){
            bucket[i.second].push_back(i.first);
        }
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
//         for(auto i:mp){
//             pq.push({i.second, i.first});
//             if(pq.size()>k) pq.pop();
//         }
        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                ans.push_back(bucket[i][j]);
                if(ans.size() == k) return ans;
            }
        }
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        return ans;
    }
};