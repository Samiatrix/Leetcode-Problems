class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return 1;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int curr = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])  continue;
            if(nums[i]+1 == nums[i+1]){
                curr++;
            }
            else{
                curr = 1;
            }
            ans = max(ans, curr);
        }
        // sort(nums.begin(), nums.end(), greater<int>());
        // curr = 1;
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i] == nums[i+1]-1){
        //         curr++;
        //     }
        //     else{
        //         curr = 1;
        //     }
        //     ans = max(ans, curr);
        // }
        return ans;
    }
};