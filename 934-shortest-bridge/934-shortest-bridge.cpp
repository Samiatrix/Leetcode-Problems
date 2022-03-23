class Solution {
public:
    void paint(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>& q){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        paint(i+1, j, grid, q);
        paint(i-1, j, grid, q);
        paint(i, j-1, grid, q);
        paint(i, j+1, grid, q);
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool good = false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    paint(i, j, grid, q);
                    good = true;
                    break;
                }
            }
            if(good)    break;
        }
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = curr.first + dir[i][0];
                    int ny = curr.second + dir[i][1];
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()){
                        if(grid[nx][ny] == 1){
                            return grid[curr.first][curr.second]-2;
                        }
                        else if(grid[nx][ny] == 0){
                            grid[nx][ny] = grid[curr.first][curr.second] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};