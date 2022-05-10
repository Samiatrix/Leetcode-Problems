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
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int ind = prices.size()-1;ind>=0;ind--){
            for(int canBuy = 0;canBuy<=1;canBuy++){
                if(canBuy){
                    dp[ind][canBuy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else{
                    dp[ind][canBuy] = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};