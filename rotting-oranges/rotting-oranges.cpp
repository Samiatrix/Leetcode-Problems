class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int x, int y){
        return x<grid.size() && x>=0 && y>=0 && y<grid[x].size() && grid[x][y] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)    fresh++;
            }
        }
        if(fresh == 0)  return 0;
        vector<int> dirx = {-1, 0, 1, 0};
        vector<int> diry = {0, -1, 0, 1};
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int c=0;c<s;c++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newX = x+dirx[i];
                    int newY = y+diry[i];
                    if(isSafe(grid, newX, newY)){
                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return fresh ? -1 : ans-1;
    }
};