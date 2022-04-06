class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int first = nums[0], last = nums.back();
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]) l = m+1;
            else    r = m;
        }
        int diff = l;
        l = 0, r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            int actualMid = (m+diff)%nums.size();
            if(nums[actualMid] == target)   return actualMid;
            if(nums[actualMid]<target)  l = m+1;
            else    r = m-1;
        }
        return -1;
    }
};