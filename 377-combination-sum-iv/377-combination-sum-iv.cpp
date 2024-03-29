class Solution {
public:
    int sum(vector<int>& nums, int i, int t, vector<vector<int>>& dp){
        if(i == nums.size() || t<=0){
            return (t == 0) ? 1 : 0;
        }
        if(dp[i][t]!=-1)    return dp[i][t];
        int take = sum(nums, 0, t-nums[i], dp);
        int notTake = sum(nums, i+1, t, dp);
        return dp[i][t] = take+notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return sum(nums, 0, target, dp);
    }
};