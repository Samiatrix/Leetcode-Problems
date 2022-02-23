struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int n = nums.size();
        vector<vector<int>> buc(n+1);
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        
        for(auto i:mp){
            int f = i.second;
            buc[f].push_back(i.first);
        }
        
        vector<int> ans;
        for(int i = buc.size()-1;i>=0 && k;i--){
            if(buc[i].size()!=0){
                for(auto j:buc[i]){
                    ans.push_back(j);
                    k--;
                    if(k == 0)  return ans;
                }
            }
        }
        
        return ans;
    }
};