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
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), 0));
        dp.back() = triangle.back();
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int bot = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(bot, dia);
            }
        }
        return dp[0][0];
        // return sum(triangle, 0, 0, dp);
    }
};