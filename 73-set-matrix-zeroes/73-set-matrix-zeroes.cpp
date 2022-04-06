class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> found;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0)   found.push_back({i, j});
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(auto f:found){
                matrix[i][f.second] = 0;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            for(auto f:found){
                matrix[f.first][i] = 0;
            }
        }
    }
};