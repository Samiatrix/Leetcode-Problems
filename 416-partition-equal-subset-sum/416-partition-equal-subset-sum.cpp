class Solution {
public:
    bool part(int n, int k, vector<int>& arr){
        vector<bool> dp(k+1, false), t(k+1, false);
        dp[0] = true;
        t[0] = true;
        if(arr[0]<=k)    dp[arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool take = (j>=arr[i] ? dp[j-arr[i]] : false);
                bool notTake = dp[j];
                t[j] = take | notTake;
            }
            dp = t;
        }
        return dp[k];
    }
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1)    return false;
        int sum = 0;
        for(auto i:nums)    sum+=i;
        // if(nums.size()&1)   return false;
        if(sum&1)   return false;
        sum/=2;
        return part(nums.size()-1, sum, nums);
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum+1, false));
        for(int i=0;i<nums.size();i++)  dp[i][0] = true;
        dp[0][nums[0]] = true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool take = (j>=nums[i] ? dp[i-1][j-nums[i]] : false);
                bool notTake = dp[i-1][j];
                dp[i][j] = take | notTake;
            }
        }
        return dp[nums.size()-1][sum];
        // return part(nums.size()-1, sum, nums);
    }
};