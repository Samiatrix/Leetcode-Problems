class Solution {
public:
    /*
    int edit(string& s, int i, string& t, int j, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i] == t[j])    return dp[i][j] = edit(s, i-1, t, j-1, dp);
        else{
            return dp[i][j] = 1+min({edit(s, i-1, t, j, dp), edit(s, i, t, j-1, dp), edit(s, i-1, t, j-1, dp)});
        }
    }*/
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i=1;i<=m;i++){
            prev[i] = i;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1])    curr[j] = prev[j-1];
                else{
                    curr[j] = 1+min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            prev = curr;
        }
        return prev[m];
        // return edit(word1, n-1, word2, m-1, dp);
    }
};