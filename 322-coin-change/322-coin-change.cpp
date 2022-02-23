class Solution {
public:
    int change(vector<int>& coins, int amount, int n, vector<vector<long>>& dp){
        if(n<0 || amount<0) return INT_MAX;
        if(amount == 0) return 0;
        if(dp[amount][n]!=-1)   return dp[amount][n];
        int take = change(coins, amount-coins[n], n, dp);
        int notTake = change(coins, amount, n-1, dp);
        return dp[amount][n] = min(notTake, take != INT_MAX ? take+1 : INT_MAX);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long>> dp(amount+1, vector<long>(coins.size()+1, -1));
        int ans = change(coins, amount, coins.size()-1, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};