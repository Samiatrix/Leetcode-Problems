class Solution {
public:
    int total(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == triangle.size()-1)    return triangle[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int bel = triangle[i][j] + total(i+1, j, triangle, dp);
        int dia = triangle[i][j] + total(i+1, j+1, triangle, dp);
        return dp[i][j] = min(bel, dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        return total(0, 0, triangle, dp);
    }
};