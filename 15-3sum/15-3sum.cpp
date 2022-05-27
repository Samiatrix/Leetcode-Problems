class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            int tar = -nums[i];
            while(l<r){
                if(nums[l]+nums[r] == tar){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1])  l++;
                    while(l<r && nums[r] == nums[r-1])  r--;
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < tar)    l++;
                else    r--;
            }
        }
        return ans;
    }
};