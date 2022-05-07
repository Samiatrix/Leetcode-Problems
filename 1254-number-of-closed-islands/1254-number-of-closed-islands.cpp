class Solution {
public:
    void dfs(vector<vector<int>>& A, int i, int j){
        if(i<0 || i>=A.size() || j<0 || j>=A[0].size() || A[i][j] == 1){
            return;
        }
        A[i][j] = 1;
        dfs(A, i-1, j);
        dfs(A, i+1, j);
        dfs(A, i, j-1);
        dfs(A, i, j+1);
        
    }
    int closedIsland(vector<vector<int>>& A) {
        int ans=0;
        for(int i=0;i<A[0].size();i++){
            if(A[0][i] == 0){
                dfs(A, 0, i);
            }
            if(A[A.size()-1][i] == 0){
                dfs(A, A.size()-1, i);
            }
        }
        for(int i=0;i<A.size();i++){
            if(A[i][0] == 0){
                dfs(A, i, 0);
            }
            if(A[i][A[0].size()-1] == 0){
                dfs(A, i, A[0].size()-1);
            }
        }
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j] == 0){
                    ans++;
                    dfs(A, i, j);
                }
            }
        }
        return ans;
    }
};