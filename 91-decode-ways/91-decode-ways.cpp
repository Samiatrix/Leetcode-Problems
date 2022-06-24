class Solution {
public:
    int decode(string s, int ind, vector<int>& dp){
        if(ind>=s.size())   return 1;
        if(s[ind] == '0')   return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans = decode(s, ind+1, dp);
        if(ind+1 < s.size() && (s[ind] == '1' || s[ind] == '2' && s[ind+1] <= '6')){
            ans += decode(s, ind+2, dp);
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return decode(s, 0, dp);
    }
};