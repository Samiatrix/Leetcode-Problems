class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& color){
        for(auto no:graph[curr]){
            if(color[no] == -1){
                color[no] = 1-color[curr];
                if(!dfs(no, graph, color)) return false;
            }
            else if(color[no] == color[curr])   return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1, -1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 1;
                if(!dfs(i, graph, color))   return false;
            }
        }
        return true;
    }
};