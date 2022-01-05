class Solution {
public:
    void dfs(vector<int>& can, int tar, int ind, vector<int> curr, vector<vector<int>>& ans){
        if(tar<0)   return;
        else if(tar == 0){
            ans.push_back(curr);
            return;
        }
        else{
            for(int i=ind;i<can.size();i++){
                if(i>ind && can[i] == can[i-1]) continue;
                curr.push_back(can[i]);
                dfs(can, tar-can[i], i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, curr, ans);
        return ans;
    }
};