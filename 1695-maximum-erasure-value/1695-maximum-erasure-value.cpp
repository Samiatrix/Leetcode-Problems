class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i=0, j=0;j<nums.size();j++){
            mp[nums[j]]++;
            sum+=nums[j];
            while(mp[nums[j]]>1){
                sum-=nums[i];
                mp[nums[i++]]--;   
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};