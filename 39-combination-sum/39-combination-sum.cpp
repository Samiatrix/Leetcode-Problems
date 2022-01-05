class Solution {
public:
    void dfs(vector<int>& can, int tar, vector<int> curr, vector<vector<int>>& ans, int ind){
        if(tar<0)   return;
        if(ind == can.size())   return;
        if(tar == 0){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(can[ind]);
        dfs(can, tar-can[ind], curr, ans, ind);
        curr.pop_back();
        dfs(can, tar, curr, ans, ind+1);
        // dfs(can, tar-can[ind], curr, ans, ind+1);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, curr, ans, 0);
        return ans;
    }
};