class Solution {
public:
    int houseRobber(vector<int>& nums, int n, vector<int>& dp){
        if(n == 0)  return nums[0];
        if(dp[n]!=-1)   return dp[n];
        int take = nums[n];
        if(n>1) take+=houseRobber(nums, n-2, dp);
        int notTake = houseRobber(nums, n-1, dp);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return houseRobber(nums, nums.size()-1, dp);
    }
};