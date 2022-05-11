class Solution {
public:
    void sub(vector<int>& nums, int ind, vector<int> curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            curr.push_back(nums[i]);
            sub(nums, i+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sub(nums, 0, curr, ans);
        return ans;
    }
};