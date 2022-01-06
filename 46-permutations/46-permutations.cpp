class Solution {
public:
    void dfs(vector<int>& nums, int ind, vector<int> curr, vector<vector<int>>& ans){
        if(ind>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i], nums[ind]);
            dfs(nums, ind+1, curr, ans);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(nums, 0, curr, ans);
        return ans;
    }
};