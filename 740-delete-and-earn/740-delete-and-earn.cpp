class Solution {
public:
    int maxPoints(vector<int>& nums, int curr, unordered_map<int, int>& mp, vector<int>& dp){
        // cout<<curr<<" "<<nums[curr]<<" "<<left<<" "<<right<<endl;
        if(curr < 0)    return 0;
        // if(curr == 0){
        //     int res = ((nums[curr] != left && nums[curr] != right) ? (mp[nums[curr]]*nums[curr]) : -1e8);
        //     // cout<<curr<<" "<<nums[curr]<<" "<<left<<" "<<right<<" "<<res<<endl;
        //     // cout<<endl;
        //     return res;
        // }
        // cout<<curr<<" "<<nums[curr]<<" "<<left<<" "<<right<<endl;
        // cout<<"now Take "<<nums[curr]<<endl;
        if(dp[curr]!=-1)    return dp[curr];
        int take = (mp[nums[curr]]*nums[curr]);
        int ind = curr-1;
        while(ind>=0 && nums[ind] == nums[curr]-1)    ind--;
        return dp[curr] = max(take+maxPoints(nums, ind, mp, dp), maxPoints(nums, curr-1, mp, dp));
        // cout<<nums[curr]<<" Take "<<take<<endl;
        // cout<<"now NotTake "<<nums[curr]<<endl;
        // int notTake = maxPoints(nums, curr-1, left, right, mp);
        // cout<<nums[curr]<<" NotTake "<<take<<endl;
        
        // cout<<curr<<" "<<nums[curr]<<" "<<left<<" "<<right<<" "<<take<<" "<<notTake<<endl;
        // return max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i:nums)    mp[i]++;
        nums.clear();
        for(auto i:mp)  nums.push_back(i.first);
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);
        // for(auto i:nums)    cout<<i<<" "<<mp[i]<<endl;
        return maxPoints(nums, nums.size()-1, mp, dp);
    }
};