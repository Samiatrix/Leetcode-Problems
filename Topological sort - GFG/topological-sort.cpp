// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(unordered_map<int, vector<int>>& adj, int ind, vector<bool>& vis, stack<int>& s){
	    if(vis[ind])   return ;
	    vis[ind] = true;
	    for(auto i:adj[ind]){
            dfs(adj, i, vis, s);
	    }
	    s.push(ind);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int, vector<int>> ad;
	    vector<int> indegree(V, 0);
	    for(int i = 0;i<V;i++){
	        for(auto j:adj[i]){
                ad[i].push_back(j);
                indegree[j]++;
	        }
	    }
	   // vector<bool> vis(V, false);
	   // stack<int> s;
	   // for(int i=0;i<V;i++){
    // 	    dfs(ad, i, vis, s);
	   // }
	    vector<int> ans;
	   // while(!s.empty()){
	   //     ans.push_back(s.top());
	   //     s.pop();
	   // }
	   // return ans;
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(indegree[i] == 0){
	           q.push(i);
	       }
	   }
	   while(!q.empty()){
	       auto curr = q.front();
	       q.pop();
	       ans.push_back(curr);
	       for(auto i:ad[curr]){
	           indegree[i]--;
	           if(indegree[i] == 0){
	               q.push(i);
	           }
	       }
	   }
	   return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends