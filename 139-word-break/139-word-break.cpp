class Solution {
public:
    bool word(int ind, string s, unordered_set<string>& st, vector<int>& dp){
        if(ind == s.size()) return 1;
        string curr = "";
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.size();i++){
            if(st.count(curr+=s[i]) && word(i+1, s, st, dp))    return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return word(0, s, st, dp);
    }
};