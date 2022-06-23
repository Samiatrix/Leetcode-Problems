class Solution {
public:
    bool sub(vector<int>& nums, int ind, int tar, vector<vector<int>>& dp){
        if(ind>=nums.size())    return false;
        if(nums[ind] == tar)  return true;
        if(dp[ind][tar]!=-1)    return dp[ind][tar];
        bool notTake = sub(nums, ind-1, tar, dp);
        bool take = false;
        if(tar>=nums[ind])  take = sub(nums, ind-1, tar-nums[ind], dp);
        return dp[ind][tar] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum & 1) return false;
        int tar = sum/2;
        // vector<vector<int>> dp(nums.size()+1, vector<int>(tar+1, -1));
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, false));
        // return sub(nums, 0, tar, dp);
        for(int i=0;i<nums.size();i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i=1;i<nums.size();i++){
            for(int j = 1;j<=tar;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i])  take = dp[i-1][j-nums[i]];
                dp[i][j] = take | notTake;
            }
        }
        return dp[nums.size()-1][tar];
    }
};