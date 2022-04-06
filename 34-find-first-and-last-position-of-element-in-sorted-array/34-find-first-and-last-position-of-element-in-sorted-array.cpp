class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int first = INT_MAX, last = INT_MIN;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                first = min(first, m);
            }
            if(nums[m]<target){
                l = m+1;
            }
            else r = m-1;
        }
        l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                last = max(last, m);
            }
            if(nums[m]<=target){
                l = m+1;
            }
            else r = m-1;
        }
        if(first == INT_MAX && last == INT_MIN) return {-1, -1};
        
                
        return {first, last};
    }
};