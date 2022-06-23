class Solution {
public:
    int profit(vector<int>& prices, int ind, int buy, int k, vector<vector<vector<int>>>& dp){
        if(ind>=prices.size())  return 0;
        if(k == 0)  return 0;
        if(dp[ind][buy][k]!=-1)    return dp[ind][buy][k];
        int pro = 0;
        if(buy){
            pro = max(profit(prices, ind+1, buy, k, dp), -prices[ind] + profit(prices, ind+1, 0, k, dp));
        }
        else{
            pro = max(profit(prices, ind+1, buy, k, dp), prices[ind] + profit(prices, ind+1, 1, k-1, dp));
        }
        return dp[ind][buy][k] = pro;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return profit(prices, 0, 1, k, dp);
    }
};