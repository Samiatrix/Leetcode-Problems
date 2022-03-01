class Solution {
public:
    int contig(vector<int>& nums, int ind, int tar){
        int sum = 0;
        int count = 0;
        for(int i=ind;i<nums.size();i++){
            sum+=nums[i];
            count++;
            if(sum>=tar)    break;
        }
        return count;
    }
    int minSubArrayLen(int tar, vector<int>& nums) {
        // int l = 0, r = nums.size()-1;
        // int mini = INT_MAX;
        // while(l<r){
        //     int m = l+(r-l)/2;
        //     int count = contig(nums, m, tar);
        //     if(count<)
        // }
        int ans = INT_MAX;
        int curr = 0;
        for(int i=0, j = 0;j<nums.size();j++){
            curr+=nums[j];
            while(curr>=tar){
                ans = min(ans, j-i+1);
                curr-=nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};