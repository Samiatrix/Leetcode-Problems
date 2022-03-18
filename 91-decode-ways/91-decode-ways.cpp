class Solution {
public:
    int decode(string s, int i, vector<int>& dp){
        if(i == s.size())   return 1;
        else if(i>s.size()) return 0;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1)   return dp[i];
        int single = decode(s, i+1, dp);
        if(i<s.size()-1 && (s[i] == '1' || (s[i]=='2' && s[i+1]<='6')))    single+=decode(s, i+2, dp);
        return dp[i] = single;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return decode(s, 0, dp);
    }
};