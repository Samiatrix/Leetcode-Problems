class Solution {
public:
    int coin(vector<int>& coins, int i, int t, vector<vector<int>>& dp){
        if(i<0) return INT_MAX;
        if(t<0) return INT_MAX;
        if(t == 0)   return 0;
        if(dp[i][t]!=-1)    return dp[i][t];
        int take = INT_MAX;
        if(coins[i]<=t) take = coin(coins, i, t-coins[i], dp);
        int notTake = coin(coins, i-1, t, dp);
        return dp[i][t] = min(take == INT_MAX ? INT_MAX : 1+take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = coin(coins, coins.size()-1, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};