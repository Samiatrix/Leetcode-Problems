// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool cycle(int ind, vector<bool>& vis, vector<int> adj[]){
        queue<pair<int, int>> q;
        q.push({ind, -1});
        vis[ind] = true;
        while(!q.empty()){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto i:adj[curr]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push({i, curr});
                }
                else if(i!=par){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(i, vis, adj))    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends