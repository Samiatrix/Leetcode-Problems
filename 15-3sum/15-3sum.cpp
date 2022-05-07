class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int t = -nums[i];
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                if(sum == t){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l+1] == nums[l]) l++;
                    while(l<r && nums[r-1] == nums[r]) r--;
                }
                if(sum < t){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};