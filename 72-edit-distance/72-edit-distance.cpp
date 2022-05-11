class Solution {
public:
    int dist(string s, int i, string t, int j, vector<vector<int>>& dp){
        if(i == 0)  return j;
        if(j == 0)  return i;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i-1] == t[j-1])    return dp[i][j] = dist(s, i-1, t, j-1, dp);
        else{
            return dp[i][j] = 1+min({dist(s, i-1, t, j, dp), dist(s, i, t, j-1, dp), dist(s, i-1, t, j-1, dp)});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dist(word1, n, word2, m, dp);
    }
};