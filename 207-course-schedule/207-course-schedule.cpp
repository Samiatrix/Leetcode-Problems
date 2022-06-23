class Solution {
public:
    bool cycle(int ind, vector<bool>& vis, vector<bool>& dfsVis, unordered_map<int, vector<int>>& adj, stack<int>& s){
        vis[ind] = true;
        dfsVis[ind] = true;
        for(auto i:adj[ind]){
            if(!vis[i]){
                if(cycle(i, vis, dfsVis, adj, s))   return true;
            }
            else if(dfsVis[i])  return true;
        }
        s.push(ind);
        dfsVis[ind] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        stack<int> s;
        vector<bool> vis(numCourses, false);
        vector<bool> dfsVis(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i, vis, dfsVis, adj, s))   return false;
            }
        }
        return s.size() == numCourses;
    }
};