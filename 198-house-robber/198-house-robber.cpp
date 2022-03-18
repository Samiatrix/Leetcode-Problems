class Solution {
public:
    int robber(vector<int>& nums, int i, vector<int>& dp){
        if(i == 0)  return nums[0];
        if(dp[i]!=-1)   return dp[i];
        int take = nums[i];
        if(i>1) take += robber(nums, i-2, dp);
        int notTake = robber(nums, i-1, dp);
        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robber(nums, nums.size()-1, dp);
    }
};