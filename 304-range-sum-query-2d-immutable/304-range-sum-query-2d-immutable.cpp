class NumMatrix {
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        vector<int> t;
        for(int i=0;i<matrix.size();i++){
            int s=0;
            
            t.push_back(0);
            for(int j=0;j<matrix[0].size();j++){
                s += matrix[i][j];
                t.push_back(s);
            }
            m.push_back(t);
            t.clear();
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        col1++,col2++;
        for(int i=row1;i<=row2;i++){
            ans += m[i][col2] - m[i][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */