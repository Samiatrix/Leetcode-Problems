class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int ind, vector<bool>& vis, vector<bool>& dfsVis, stack<int>& s, bool& possible){
        if(possible)    return;
        // if(vis[ind])    return ;
        vis[ind] = true;
        dfsVis[ind] = true;
        for(auto i:adj[ind]){
            if(!vis[i]){
                dfs(adj, i, vis, dfsVis, s, possible);
            }
            else if(dfsVis[i]){
                possible = true;
                return;
            }
        }
        dfsVis[ind] = false;
        if(!possible)   s.push(ind);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // unordered_map<int, vector<int>> adj;
        vector<int> adj[numCourses];
        
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> in(numCourses, 0);
        for(auto i:prerequisites){
            in[i[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0)  q.push(i);
        }
        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr);
            count++;
            for(auto i:adj[curr]){
                in[i]--;
                if(in[i] == 0)  q.push(i);
            }
        }
        if(count == numCourses) return ans;
        return {};
        // vector<bool> vis(numCourses, false);
        // vector<bool> dfsVis(numCourses, false);
        // stack<int> s;
        // vector<int> ans;
//         bool possible = false;
//         for(int i=0;i<numCourses;i++){
//             dfs(adj, 0, vis, dfsVis, s, possible);
//         }
        
//         if(possible)  return {};
//         while(!s.empty()){
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;
        
    }
};