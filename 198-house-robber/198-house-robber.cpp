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
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1) take += dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[nums.size()-1];
    }
};