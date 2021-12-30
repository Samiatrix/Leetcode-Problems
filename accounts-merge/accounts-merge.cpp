class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adj;

    void dfs(string s, vector<string>& account){
        visited.insert(s);
        account.push_back(s);
        for(auto mail:adj[s]){
            if(!visited.count(mail))    dfs(mail, account);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> mp;
        for(int i=0;i<accounts.size();i++){
            string name = accounts[i][0];
            string mustEmail = accounts[i][1];
            for(int j=2;j<accounts[i].size();j++){
                adj[accounts[i][j]].push_back(mustEmail);
                adj[mustEmail].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(auto acc:accounts){
            if(!visited.count(acc[1])){
                vector<string> account={acc[0]};
                dfs(acc[1], account);
                sort(account.begin()+1, account.end());
                ans.push_back(account);
            }
        }
        return ans;
    }
};