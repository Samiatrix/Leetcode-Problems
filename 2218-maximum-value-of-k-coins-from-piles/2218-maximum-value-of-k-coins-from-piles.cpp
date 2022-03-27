class Solution {
public:
    int val(vector<vector<int>>& piles, int i, int k, vector<vector<long>>& dp){
        if(i == piles.size())   return 0;
        if(k == 0)  return 0;
        if(dp[i][k]!=-1)    return dp[i][k];
        int ans = val(piles, i+1, k, dp);
        int curr = 0;
        for(int j=0;j<piles[i].size() && j<k;j++){
            curr += piles[i][j];
            ans = max(ans, curr + val(piles, i+1, k-(j+1), dp));
        }
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<long>> dp(piles.size(), vector<long>(k+1, -1));
        return val(piles, 0, k, dp);
    }
};