class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                nums[ind++] = nums[i];
            }
            else if(nums[ind-1]!=nums[i]){
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};