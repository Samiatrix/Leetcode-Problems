class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1, -1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    for(auto no:graph[curr]){
                        if(color[no] == -1){
                            color[no] = 1-color[curr];
                            q.push(no);
                        }
                        else if(color[no] == color[curr])   return false;
                    }
                }
            }
        }\
        return true;
    }
};