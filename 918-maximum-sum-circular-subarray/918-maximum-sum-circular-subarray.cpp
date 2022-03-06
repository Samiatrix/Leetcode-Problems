class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int n = nums.size()*2;
        int n = nums.size();
        int curr = 0, ans1 = nums[0];
        int cur = 0, ans2 = nums[0];
        int sum = 0;
        for(int i=0;i<n;i++){
            curr = max(curr+nums[i], nums[i]);
            ans1 = max(ans1, curr);
            
            cur = min(cur+nums[i], nums[i]);
            ans2 = min(ans2, cur);

            sum+=nums[i];            
        }
        return ans1 > 0 ? max(ans1, sum-ans2) : ans1;
    }
};