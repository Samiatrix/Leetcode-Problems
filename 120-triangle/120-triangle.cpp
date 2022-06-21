class Solution {
public:
    int sum(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        if(i == mat.size()-1){
            return mat[i][j];
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int bot = mat[i][j] + sum(mat, i+1, j, dp);
        int dia = mat[i][j] + sum(mat, i+1, j+1, dp);
        return dp[i][j] = min(bot, dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        return sum(triangle, 0, 0, dp);
    }
};