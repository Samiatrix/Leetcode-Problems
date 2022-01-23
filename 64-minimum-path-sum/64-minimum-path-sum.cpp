class Solution {
public:
    int sum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0)    return grid[0][0];
        if(i<0 || j<0)  return INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];
        int u = sum(grid, i-1, j, dp);
        int l = sum(grid, i, j-1, dp);
        return dp[i][j] = grid[i][j] + min(u, l);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return sum(grid, n-1, m-1, dp);
    }
};