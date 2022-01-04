class Solution {
public:
    void subset(vector<int>& nums, int ind, int n, vector<int> curr, set<vector<int>>& ans){
        if(ind == n){
            ans.insert(curr);
            return ;
        }
        subset(nums, ind+1, n, curr, ans);
        curr.push_back(nums[ind]);
        subset(nums, ind+1, n, curr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        subset(nums, 0, nums.size(), curr, ans);
        vector<vector<int>> res;
        for(auto i:ans) res.push_back(i);
        return res;
    }
};