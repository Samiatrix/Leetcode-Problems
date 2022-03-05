class Solution {
public:
    int maxPoints(vector<int>& nums, int curr, unordered_map<int, int>& mp, vector<int>& dp){
        if(curr < 0)    return 0;
        if(dp[curr]!=-1)    return dp[curr];
        int take = (mp[nums[curr]]*nums[curr]);
        int ind = curr-1;
        while(ind>=0 && nums[ind] == nums[curr]-1)    ind--;
        return dp[curr] = max(take+maxPoints(nums, ind, mp, dp), maxPoints(nums, curr-1, mp, dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        nums.clear();
        for(auto i:mp)  nums.push_back(i.first);
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);
        return maxPoints(nums, nums.size()-1, mp, dp);
    }
};