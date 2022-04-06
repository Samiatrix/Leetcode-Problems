class Solution {
public:
    int dec(string s, int i, vector<int>& dp){
        if(i == s.size())   return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1)   return dp[i];
        int ans = dec(s, i+1, dp);
        if((i+1)<s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) ans+=dec(s, i+2, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return dec(s, 0, dp);
    }
};