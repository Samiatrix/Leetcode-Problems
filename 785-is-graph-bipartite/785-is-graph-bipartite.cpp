class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1, -1);
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push({i, 1});
                
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    color[curr.first] = 1-curr.second;
                    // cout<<curr.first<<" "<<curr.second<<" "<<color[curr.first]<<endl;
                    for(auto no:graph[curr.first]){
                        // cout<<"int adj "<<no<<endl;
                        if(color[no] == -1){
                            q.push({no, color[curr.first]});
                        }
                        else if(color[no] == color[curr.first])   return false;
                    }
                }
            }
        }
        return true;
    }
};