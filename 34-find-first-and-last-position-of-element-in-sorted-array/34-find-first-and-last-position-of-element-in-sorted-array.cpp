class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = -1, high = -1;
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                low = m;
            }
            if(nums[m] >= target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                high = m;
            }
            if(nums[m] > target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return {low, high};
    }
};