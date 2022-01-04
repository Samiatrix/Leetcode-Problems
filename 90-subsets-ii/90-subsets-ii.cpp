class Solution {
public:
    void subset(vector<int>& nums, int ind, vector<int> curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            if(ind == i || nums[i]!=nums[i-1]){
                curr.push_back(nums[i]);
                subset(nums, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        subset(nums, 0, curr, ans);
        return ans;
    }
};