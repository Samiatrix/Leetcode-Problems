class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<int>& vis, int ind){
        vis[ind] = 1;
        for(int j=0;j<grid[ind].size();j++){
            if(ind == j)    continue;
            if(!vis[j] && grid[ind][j]){
                dfs(grid, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> vis(isConnected.size(), 0);
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected, vis, i);
            }
        }
        return ans;
    }
};