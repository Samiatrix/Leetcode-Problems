class Solution {
public:
    int rob(vector<int>& nums, int ind, vector<int>& dp){
        if(ind<0)   return 0;
        if(dp[ind]!=-1) return dp[ind];
        int notTake = rob(nums, ind-1, dp);
        int take = nums[ind];
        if(ind>1)   take += rob(nums, ind-2, dp);
        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return rob(nums, nums.size()-1, dp);
    }
};