class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        if(nums.size()<3)   return 0;
        int count = 0;
        int prev = nums[1]-nums[0];
        for(int i=1;i<nums.size()-1;i++){
            int diff = nums[i+1]-nums[i];
            
            if(prev == diff){
                count++;
            }
            else{
                prev = diff;
                count = 0;
            }
            
            ans += count;
        }
        return ans;
    }
};