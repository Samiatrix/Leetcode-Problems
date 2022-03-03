class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        if(nums.size()<3)   return 0;
        for(int i=0;i<nums.size()-2;i++){
            int prev = nums[i+1]-nums[i];
            // int curr = 0;
            for(int j=i+1;j<nums.size()-1;j++){
                int diff = nums[j+1]-nums[j];
                
                if(diff == prev){
                    ans++;
                }
                else{
                    break;
                }
            }
            
        }
        return ans;
    }
};