class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto i:words){
            mp[i]++;
        }
        vector<string> ans;
        vector<vector<string>> buc(words.size()+1);
        for(auto i:mp){
            buc[i.second].push_back(i.first);
        }
        for(int i=buc.size()-1;i>=0;i--){
            sort(buc[i].begin(), buc[i].end());
        }
        for(int i=buc.size()-1;i>=0;i--){
            if(buc[i].size()!=0){
                for(auto j:buc[i]){
                    ans.push_back(j);
                    k--;
                    if(k == 0){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};