class Solution {
public:
    bool cycle(int curr, vector<bool>& dfsVis, unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        vis[curr] = true;
        dfsVis[curr] = true;
        for(auto node:adj[curr]){
            if(!vis[node]){
                if(cycle(node, dfsVis, adj, vis))   return true;
            }
            else if(dfsVis[node])  return true;
        }
        dfsVis[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0)   return true;
        unordered_map<int, vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        // stack<int> s;
        vector<bool> vis(numCourses, false);
        vector<bool> dfsVis(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i, dfsVis, adj, vis))   return false;
            }
        }
        return true;
        
    }
};