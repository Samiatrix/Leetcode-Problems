class Solution {
public:
    int mod = 1e9+7;
    long long dec(string& s, int i, vector<long long>& dp){
        if(i >= s.size())   return 1;
        if(dp[i]!=-1)   return dp[i];
        
        if(s[i] == '0') return dp[i] = 0;
        
        long long ans = 0;
        if(s[i] == '*') ans += (9 * dec(s, i+1, dp));
        else    ans += dec(s, i+1, dp);
        
        if(s[i] == '*'){
            if(i<s.size()-1 && s[i+1]>='0' && s[i+1]<='9')  ans += dec(s, i+2, dp);
            if(i<s.size()-1 && s[i+1] == '*')   ans += 9*(dec(s, i+2, dp));
            
            if(i<s.size()-1 && s[i+1]>='0' && s[i+1]<='6')  ans+=dec(s, i+2, dp);
            if(i<s.size()-1 && s[i+1] == '*')   ans += 6*dec(s, i+2, dp);
        }
        else if(s[i] == '1' && i<s.size()-1){
            if(s[i+1]>='0' && s[i+1]<='9')  ans += dec(s, i+2, dp);
            else if(s[i+1] == '*')   ans += 9*(dec(s, i+2, dp));
        }
        else if(s[i] == '2' && i<s.size()-1){
            if(s[i+1]>='0' && s[i+1]<='6')  ans+=dec(s, i+2, dp);
            else if(s[i+1] == '*')   ans += 6*dec(s, i+2, dp);
        }
        return dp[i] = ans%mod;
    }
    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return dec(s, 0, dp);
    }
};