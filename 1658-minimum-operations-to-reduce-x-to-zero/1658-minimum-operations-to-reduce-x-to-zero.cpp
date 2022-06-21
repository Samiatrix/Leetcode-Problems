class Solution {
public:
    int op(vector<int>& nums, int x, int l, int r, vector<vector<vector<int>>>& dp){ 
        if(x == 0)  return 0;
        if(l>r) return 1e9+7;
        if(x<0) return 1e9+7;
        if(dp[l][r][x]!=-1) return dp[l][r][x];
        int left = 1+op(nums, x-nums[l], l+1, r, dp);
        int right = 1+op(nums, x-nums[r], l, r-1, dp);
        return dp[l][r][x] = min(left, right);
    }
    int minOperations(vector<int>& nums, int x) {
        // vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>>(nums.size()+1, vector<int>(x, -1)));
        int sum = 0, ans = 0;
        for(auto i:nums)    sum+=i;
        int tar = sum-x;
        if(tar == 0)    return nums.size();
        int curr = 0;
        for(int i=0, j=0;j<nums.size();j++){
            curr += nums[j];
            // cout<<curr<<endl;
            while(i<j && curr>tar){
                curr-=nums[i++];
            }
            // cout<<curr<<" "<<tar<<endl;
            // cout<<endl;
            if(curr == tar){
                ans = max(ans, j-i+1);
            }
        }
        return ans == 0 ? -1 : nums.size()-ans;
        // int ans = op(nums, x, 0, nums.size()-1, dp);
        // return ans >= 1e9+7 ? -1 : ans;
    }
};