class Solution {
public:
    int profit(vector<int>& pr, int buy, int ind, vector<vector<int>>& dp){
        if(ind == pr.size())    return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-pr[ind] + profit(pr, 0, ind+1, dp), profit(pr, 1, ind+1, dp));
        }
        else{
            return dp[ind][buy] = max(pr[ind]+profit(pr, 1, ind+1, dp), profit(pr, 0, ind+1, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profit(prices, 1, 0, dp);
    }
};