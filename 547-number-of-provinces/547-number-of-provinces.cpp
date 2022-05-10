class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        vis[i] = true;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};