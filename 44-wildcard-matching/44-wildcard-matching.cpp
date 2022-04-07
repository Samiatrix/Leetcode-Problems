class Solution {
public:
    bool mat(string& s, int i, string& p, int j, vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*')   return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = mat(s, i-1, p, j-1, dp);
        if(p[j] == '*') return dp[i][j] = mat(s, i-1, p, j, dp) || mat(s, i, p, j-1, dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return mat(s, s.size()-1, p, p.size()-1, dp);
    }
};