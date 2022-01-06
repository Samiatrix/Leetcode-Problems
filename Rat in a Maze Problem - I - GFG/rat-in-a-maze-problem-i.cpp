// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    unordered_set<string> s;
    void dfs(vector<vector<int>>& g, int n, int i, int j, string curr, vector<string>& ans){
        // string ch = to_string(i)+"#"+to_string(j);
        // || s.count(ch)
        if(i<0 || i>=n || j<0 || j>=n || g[i][j] == 0)   return ;
        // s.insert(ch);
        if(i == n-1 && j == n-1){
            ans.push_back(curr);
            return;
        }
        g[i][j] = 0;
        dfs(g, n, i+1, j, curr+"D", ans);
        dfs(g, n, i, j-1, curr+"L", ans);
        dfs(g, n, i, j+1, curr+"R", ans);
        dfs(g, n, i-1, j, curr+"U", ans);
        g[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string curr="";
        dfs(m, n, 0, 0, curr, ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends