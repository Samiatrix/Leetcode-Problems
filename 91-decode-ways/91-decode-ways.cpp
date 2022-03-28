class Solution {
public:
    int dec(string s, int i, vector<int>& dp){
        if(i == s.size())   return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1)   return dp[i];
        int notTake = dec(s, i+1, dp);
        int take = 0;
        if(i+1<s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))   take = dec(s, i+2, dp);
        return dp[i] = take+notTake;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return dec(s, 0, dp);
    }
};