class Solution {
public:
    int profit(int ind, int canBuy, vector<int>& prices, vector<vector<int>>&dp){
        if(ind == prices.size())    return 0;
        if(dp[ind][canBuy]!=-1) return dp[ind][canBuy];
        if(canBuy){
            return dp[ind][canBuy] = max(-prices[ind] + profit(ind+1, 0, prices, dp), profit(ind+1, 1, prices, dp));
        }
        else{
            return dp[ind][canBuy] = max(prices[ind] + profit(ind+1, 1, prices, dp), profit(ind+1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profit(0, 1, prices, dp);
    }
};