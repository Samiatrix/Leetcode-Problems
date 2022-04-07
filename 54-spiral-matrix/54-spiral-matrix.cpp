class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rs = 0, re = matrix.size()-1;
        int cs = 0, ce = matrix[0].size()-1;
        int dir = 0;
        int n = matrix.size(), m = matrix[0].size();
        while(n*m != ans.size()){
            if(dir == 0){
                for(int i=cs;i<=ce;i++){
                    ans.push_back(matrix[rs][i]);
                }
                rs++;
                dir = 1;
            }
            else if(dir == 1){
                for(int i=rs;i<=re;i++){
                    ans.push_back(matrix[i][ce]);
                }
                ce--;
                dir = 2;
            }
            else if(dir == 2){
                for(int i=ce;i>=cs;i--){
                    ans.push_back(matrix[re][i]);
                }
                re--;
                dir = 3;
            }
            else if(dir == 3){
                for(int i=re;i>=rs;i--){
                    ans.push_back(matrix[i][cs]);
                }
                cs++;
                dir = 0;
            }
        }
        return ans;
    }
};