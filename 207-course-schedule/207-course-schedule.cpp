class Solution {
public:
    // bool cycle(int curr, vector<bool>& vis, vector<bool>& dfs, unordered_map<int, vector<int>>& adj){
    //     vis[curr] = true;
    //     dfs[curr] = true;
    //     for(auto i:adj[curr]){
    //         if(!vis[i]){
    //             if(cycle(i, vis, dfs, adj)) return true;
    //         }
    //         else if(dfs[i]) return true;
    //     }
    //     dfs[curr] = false;
    //     return false;
    // }
    void cycle(int curr, vector<bool>& vis, unordered_map<int, vector<int>>& adj, stack<int>& s){
        vis[curr] = true;
        for(auto i:adj[curr]){
            if(!vis[i]){
                cycle(i, vis, adj, s);
            }
        }
        s.push(curr);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        vector<bool> vis(numCourses, false);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            count++;
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0)    q.push(i);
            }
        }
        return numCourses == count;
    }
};