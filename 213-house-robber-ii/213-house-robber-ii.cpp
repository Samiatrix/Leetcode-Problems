class Solution {
public:
    int robb(vector<int>& nums, int n, vector<int>& dp){
        if(n == 0)  return nums[n];
        if(dp[n]!=-1)   return dp[n];
        int take = nums[n];
        if(n>1) take += robb(nums, n-2, dp);
        int notTake = robb(nums, n-1, dp);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        vector<int> nums1, nums2;
        for(int i=0;i<nums.size();i++){
            if(i!=0)    nums2.push_back(nums[i]);
            if(i!=nums.size()-1)    nums1.push_back(nums[i]);
        }
        vector<int> dp1(nums1.size(), -1), dp2(nums2.size(), -1);
        return max(robb(nums1, nums1.size()-1, dp1), robb(nums2, nums2.size()-1, dp2));
    }
};