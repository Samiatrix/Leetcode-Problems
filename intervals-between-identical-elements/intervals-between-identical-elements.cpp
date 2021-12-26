class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<long long> pre(arr.size(), 0);
        vector<long long> suf(arr.size(), 0);
        vector<long long> ans;
        for(auto i:mp){
            vector<long long> ind = i.second;
            for(int j=1;j<ind.size();j++){
                pre[ind[j]] = pre[ind[j-1]] + j*(ind[j]-ind[j-1]);
            }
            for(int j=ind.size()-2;j>=0;j--){
                suf[ind[j]] = suf[ind[j+1]] + (ind.size()-1-j)*(ind[j+1]-ind[j]);
            }
        }
        for(int i=0;i<arr.size();i++){
            ans.push_back(pre[i]+suf[i]);
        }
        return ans;
    }
};