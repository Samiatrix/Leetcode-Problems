class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0)    return 0;
        grid[i][j] = 0;
        int l = dfs(grid, i+1, j);
        int r = dfs(grid, i-1, j);
        int d = dfs(grid, i, j+1);
        int u = dfs(grid, i, j-1);
        return l+r+d+u+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};