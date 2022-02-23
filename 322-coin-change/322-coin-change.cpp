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
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]) dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};