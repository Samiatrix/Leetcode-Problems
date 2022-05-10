class Solution {
public:
    int profit(int i, int buy, int cap, vector<int>& pr, vector<vector<vector<int>>>& dp){
        if(i == pr.size())  return 0;
        if(cap == 0)    return 0;
        if(dp[i][buy][cap]!=-1)  return dp[i][buy][cap];
        int pro = 0;
        if(buy){
            pro = max(-pr[i] + profit(i+1, 0, cap, pr, dp), profit(i+1, 1, cap, pr, dp));
        }
        else{
            pro = max(pr[i] + profit(i+1, 1, cap-1, pr, dp), profit(i+1, 0, cap, pr, dp));
        }        
        return dp[i][buy][cap] = pro;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(0, 1, 2, prices, dp);
    }
};