class Solution {
public:
    int lcs(string& text1, int ind1, string& text2, int ind2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0)    return 0;
        
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])  return dp[ind1][ind2] = 1 + lcs(text1, ind1-1, text2, ind2-1, dp);
        else{
            return dp[ind1][ind2] = max(lcs(text1, ind1-1, text2, ind2, dp), lcs(text1, ind1, text2, ind2-1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<m;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
                else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
        // return lcs(text1, text1.size()-1, text2, text2.size()-1, dp);
    }
};