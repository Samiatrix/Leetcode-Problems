class Solution {
public:
    int dis(string s, int n, string t, int m, vector<vector<int>>& dp){
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1)    return dp[n][m];
        if(s[n] == t[m]){
            return dp[n][m] = dis(s, n-1, t, m-1, dp) + dis(s, n-1, t, m, dp);
        }
        else    return dp[n][m] = dis(s, n-1, t, m, dp);
    }
    int numDistinct(string s, string t) {
        long long n = s.size(), m = t.size();
        vector<double> dp(m+1, 0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return dp[m];
        // return dis(s, n-1, t, m-1, dp);
    }
};