class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> nums;
        for(int i=0;i<mat.size();i++){
            int l = 0, r = mat[i].size()-1;
            while(l<=r){
                int m = l+(r-l)/2;
                if(mat[i][m] == 0){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            nums.push_back({i, l});
        }
        sort(nums.begin(), nums.end(), [](pair<int, int>& a, pair<int, int>& b){
            return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
        });
        vector<int> ans;
        for(int i=0;i<nums.size() && i<k;i++){
            ans.push_back(nums[i].first);
        }
        return ans;
    }
};