class Solution {
public:
    bool mat(string& s, int i, string& p, int j, vector<vector<int>>& dp){
        if(i<0 && j<0)  return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(s[k]!='*')   return false;
            }
            return true;
        }
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == p[j] || s[i] == '?') return dp[i][j] = mat(s, i-1, p, j-1, dp);
        if(s[i] == '*') return dp[i][j] = (mat(s, i-1, p, j, dp) | mat(s, i, p, j-1, dp));
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int m = s.size(), n = p.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<bool> prev(m+1, false), curr(m+1, false);
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        prev[0] = true;
        
        
        for(int i=1;i<=n;i++){
            
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            
            for(int j=1;j<=m;j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*'){
                    curr[j] = (prev[j] | curr[j-1]);
                }
                else    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};