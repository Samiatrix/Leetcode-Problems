class Solution {
public:
    int coin(int tar, vector<int>& coins, int ind, vector<vector<int>>& dp){
        if(ind == 0 && tar % coins[ind] == 0)   return 1;
        else if(ind == 0 && tar%coins[ind]!=0)  return 0;
        if(tar<0)   return 0;
        if(dp[ind][tar]!=-1)    return dp[ind][tar];
        int take = 0;
        if(tar>=coins[ind]) take = coin(tar-coins[ind], coins, ind, dp);
        int notTake = coin(tar, coins, ind-1, dp);
        return dp[ind][tar] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return coin(amount, coins, coins.size()-1, dp);
    }
};