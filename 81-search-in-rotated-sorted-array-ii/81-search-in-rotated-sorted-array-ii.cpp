class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[l] == target || nums[r] == target)  return true;
            if(nums[mid] == target) return true;
            
            if(nums[mid]>nums[n-1]){
                if(target<nums[mid] && nums[0]<=target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else if(nums[mid]<nums[n-1]){
                if(target>nums[mid] && target<=nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                r--;
            }
        }
        return false;
    }
};