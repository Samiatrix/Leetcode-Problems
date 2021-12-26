class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int t = 0-nums[i];
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r] <= t){
                    if(nums[l]+nums[r] == t)    s.insert({nums[i], nums[l], nums[r]});
                    // break;
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        for(auto i:s)   ans.push_back(i);
        return ans;
        
    }
};