class Solution {
public:
    int pal(string& s, int i, string& t, int j, vector<vector<int>>& dp){
        if(i<=0 || j<=0)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i-1] == t[j-1])    return dp[i][j] = 1+pal(s, i-1, t, j-1, dp);
        else    return dp[i][j] = max(pal(s, i-1, t, j, dp), pal(s, i, t, j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1] == t[j-1])    dp[i][j] = 1+dp[i-1][j-1];
                else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s.size()][s.size()];
        return pal(s, s.size(), t, t.size(), dp);
    }
};