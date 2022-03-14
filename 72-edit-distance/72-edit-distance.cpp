class Solution {
public:
    int edit(string& s, int i, string& t, int j, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i] == t[j])    return dp[i][j] = edit(s, i-1, t, j-1, dp);
        else{
            return dp[i][j] = 1+min({edit(s, i-1, t, j, dp), edit(s, i, t, j-1, dp), edit(s, i-1, t, j-1, dp)});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=m;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1])    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
        // return edit(word1, n-1, word2, m-1, dp);
    }
};