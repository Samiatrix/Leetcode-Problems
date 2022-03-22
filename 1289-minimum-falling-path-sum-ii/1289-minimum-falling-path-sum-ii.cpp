class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int firstmin = 0, secondmin = 0, pos = -1;
        for(int i=0;i<n;i++){
            int tfirstmin = INT_MAX, tsecondmin = INT_MAX, tpos = -1;
            for(int j=0;j<m;j++){
                int prevmin = pos == j ? secondmin : firstmin;
                
                if(grid[i][j] + prevmin < tfirstmin){
                    tsecondmin = tfirstmin;
                    tfirstmin = grid[i][j] + prevmin;
                    tpos = j;
                }
                else{
                    tsecondmin = min(tsecondmin, grid[i][j] + prevmin);
                }
            }
            pos = tpos, firstmin = tfirstmin, secondmin = tsecondmin;
        }
        return firstmin;
    }
};