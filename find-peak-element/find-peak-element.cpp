class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m1 = l+(r-l)/2;
            int m2 = m1+1;
            if(nums[m1]>nums[m2]){
                r = m1;
            }
            else{
                l = m2;
            }
        }
        return l;
    }
};