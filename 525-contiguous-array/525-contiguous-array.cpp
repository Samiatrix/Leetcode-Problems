class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        int ans = 0;
        mp[0] = -1;
        for(auto i=0;i<nums.size();i++){
            count += nums[i] == 1 ? 1 : -1;
            if(mp.count(count)){
                ans = max(ans, i-mp[count]);
            }
            else    mp[count] = i;
        }
        return ans;
    }
};