class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, set<string>> mp;
        for(auto s: products){
            string curr = "";
            for(auto i:s){
                curr+=i;
                mp[curr].insert(s);
            }
        }
        string curr = "";
        vector<vector<string>> ans;
        for(auto i:searchWord){
            vector<string> t;
            curr+=i;
            int k = 3;
            for(auto j:mp[curr]){
                t.push_back(j);
                k--;
                if(k == 0)  break;
            }
            ans.push_back(t);
        }
        return ans;
    }
};