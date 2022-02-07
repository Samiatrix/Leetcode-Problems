class Solution {
public:
    void dfs(int ind, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            curr.push_back(nums[i]);
            dfs(i+1, nums, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(0, nums, curr, ans);
        return ans;
    }
};