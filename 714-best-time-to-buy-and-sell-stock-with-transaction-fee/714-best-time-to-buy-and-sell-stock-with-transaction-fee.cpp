class Solution {
public:
    int profit(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp, int fee){
        if(ind>=prices.size())  return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        int pro = 0;
        if(buy){
            pro = max(profit(prices, ind+1, buy, dp, fee), -prices[ind] + profit(prices, ind+1, 0, dp, fee));
        }
        else{
            pro = max(profit(prices, ind+1, buy, dp, fee), prices[ind]-fee+profit(prices, ind+1, 1, dp, fee));
        }
        return dp[ind][buy] = pro;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profit(prices, 0, 1, dp, fee);
    }
};