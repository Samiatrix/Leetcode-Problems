class Solution {
public:
    bool dfs(int n, unordered_map<int, vector<int>>& mp, int ind, stack<int>& order, vector<bool>& vis, vector<bool>& dfsVis){
        // if(vis[ind])    return;
        vis[ind] = true;
        dfsVis[ind] = true;
        
        for(auto curr:mp[ind]){
            if(!vis[curr]){
                // vis[curr]
                if(dfs(n, mp, curr, order, vis, dfsVis))    return true;
            }
            else if(dfsVis[curr])   return true;   
        }
        dfsVis[ind] = false;
        order.push(ind);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
        }
        stack<int> order;
        vector<bool> vis(numCourses, false);
        vector<bool> dfsVis(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(numCourses, mp, i, order, vis, dfsVis))  return {};
            }
        }
        vector<int> ans;
        while(!order.empty()){
            ans.push_back(order.top());
            order.pop();
        }
        return ans;
    }
};