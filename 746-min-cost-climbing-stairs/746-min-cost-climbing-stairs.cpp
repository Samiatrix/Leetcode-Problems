class Solution {
public:
    int climb(vector<int>& cost, int n, vector<int>& dp){
        if(n <= 1)  return cost[n];
        if(dp[n]!=-1)   return dp[n];
        if(cost.size() == n)    return dp[n] = min(climb(cost, n-1, dp), climb(cost, n-2, dp));
        return dp[n] = cost[n] + min(climb(cost, n-1, dp), climb(cost, n-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return climb(cost, cost.size(), dp);
    }
};