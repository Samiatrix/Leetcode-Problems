class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int rs = 0, re = n-1;
        int cs = 0, ce = m-1;
        vector<int> ans;
        while(ans.size() != m*n){
            for(int i=cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            if(ans.size() == m*n)   return ans;
            rs++;
            for(int i=rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
            }
            if(ans.size() == m*n)   return ans;
            ce--;
            for(int i=ce;i>=cs;i--){
                ans.push_back(matrix[re][i]);
            }
            if(ans.size() == m*n)   return ans;
            re--;
            for(int i=re;i>=rs;i--){
                ans.push_back(matrix[i][cs]);
            }
            if(ans.size() == m*n)   return ans;
            cs++;
        }
        return ans;
    }
};