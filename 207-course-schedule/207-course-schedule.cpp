class Solution {
public:
    bool cycle(int curr, vector<bool>& vis, vector<bool>& dfs, unordered_map<int, vector<int>>& adj){
        vis[curr] = true;
        dfs[curr] = true;
        for(auto i:adj[curr]){
            if(!vis[i]){
                if(cycle(i, vis, dfs, adj)) return true;
            }
            else if(dfs[i]) return true;
        }
        dfs[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> dfs(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i, vis, dfs, adj)) return false;
            }
        }
        return true;
    }
};