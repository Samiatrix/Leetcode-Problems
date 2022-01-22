class Solution {
public:
    int adj(vector<int>& arr){
        int prev = arr[0];
        int prev2 = 0;
        vector<int> dp(arr.size(), 0);
        dp[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            int l = arr[i]+ (i>1 ? dp[i-2] : 0);
            int r = dp[i-1];
            dp[i] = max(l, r);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> a, b;
        for(int i=0;i<nums.size();i++){
            if(i!=0)    a.push_back(nums[i]);
            if(i!=nums.size()-1)    b.push_back(nums[i]);
        }
        int l = adj(a);
        int r = adj(b);
        return max(l, r);
    }
};