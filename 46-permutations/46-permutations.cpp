class Solution {
public:
    void dfs(vector<int>& nums, int ind, vector<vector<int>>& ans){
        if(ind>=nums.size()){
            ans.push_back(nums);
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i], nums[ind]);
            dfs(nums, ind+1, ans);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};