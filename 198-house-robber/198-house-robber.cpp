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
        // vector<int> dp(nums.size(), -1); //for recursion+memo
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int notTake = dp[i-1];
            int take = nums[i];
            if(i>1)   take += dp[i-2];
            dp[i] = max(take, notTake);
        }
        return dp[nums.size()-1];
    }
};