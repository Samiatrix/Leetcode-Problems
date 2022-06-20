class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> t;
            int sum = 0;
            t.push_back(0);
            for(int j=0;j<matrix[0].size();j++){
                t.push_back(sum+=matrix[i][j]);
            }
            pre.push_back(t);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        col1++, col2++;
        int sum = 0;
        for(int i=row1;i<=row2;i++){
            sum += pre[i][col2]-pre[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */