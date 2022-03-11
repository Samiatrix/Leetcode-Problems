class Solution {
public:
    int lcs(string& text1, int ind1, string& text2, int ind2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0)    return 0;
        if(ind1 == 0 || ind2 == 0){
            if(text1[ind1] == text2[ind2])  return 1;
            return max(lcs(text1, ind1-1, text2, ind2, dp), lcs(text1, ind1, text2, ind2-1, dp));
        }
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])  return dp[ind1][ind2] = 1 + lcs(text1, ind1-1, text2, ind2-1, dp);
        else{
            return dp[ind1][ind2] = max(lcs(text1, ind1-1, text2, ind2, dp), lcs(text1, ind1, text2, ind2-1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text1.size()-1, text2, text2.size()-1, dp);
    }
};