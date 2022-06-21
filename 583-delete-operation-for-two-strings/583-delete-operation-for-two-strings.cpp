class Solution {
public:
    int dist(string s, string t, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0)  return 0;
        if(i == 0 && j != 0)    return j;
        if(i != 0 && j == 0)    return i;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i-1] == t[j-1])    return dp[i][j] = dist(s, t, i-1, j-1, dp);
        return dp[i][j] = 1+min(dist(s, t, i-1, j, dp), dist(s, t, i, j-1, dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return dist(word1, word2, word1.size(), word2.size(), dp);
    }
};