class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        // nums[0] ? 1 : 0;
        // int num = count ? 1 : 0;
        int ans = 0;
        // for(int i=1;i<nums.size();i++){
        //     if(num == nums[i]){
        //         count++;
        //     }
        //     else{
        //         ans = max(ans, count);
        //         count = 1;
        //         num = nums[i];
        //     }
        // }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1)    count++;
            else{
                if(count)   ans = max(ans, count);
                count = 0;
            }
        }
        if(count)   ans = max(ans, count);
        return ans;
    }
};