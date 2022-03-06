class Solution {
public:
    int robber(vector<int>& nums, int n, vector<int>& dp){
        if(n == 0)  return nums[n];
        if(dp[n]!=-1)   return dp[n];
        int take = nums[n];
        if(n>1) take += robber(nums, n-2, dp);
        int notTake = robber(nums, n-1, dp);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robber(nums, nums.size()-1, dp);
    }
};