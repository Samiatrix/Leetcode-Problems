class Solution {
public:
    int dis(string s, int i, string t, int j, vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;
        // if(i == 0 && j == 0)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i-1] == t[j-1])    return dp[i][j] = dis(s, i-1, t, j-1, dp);
        else{
            return dp[i][j] = 1+min({dis(s, i-1, t, j, dp), dis(s, i, t, j-1, dp), dis(s, i-1, t, j-1, dp)});
        }
    }
    int minDistance(string word1, string word2) {
        if(word1 == "" || word2 == "")  return max(word1.size(), word2.size());
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return dis(word1, word1.size(), word2, word2.size(), dp);
    }
};