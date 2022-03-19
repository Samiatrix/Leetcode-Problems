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
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        // for(int i=)
        return pal(s, s.size(), t, t.size(), dp);
    }
};