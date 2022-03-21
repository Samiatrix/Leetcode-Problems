class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        int ans = 0;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                int x = curr[0], y = curr[1], ck = curr[2];
                if(x == n-1 && y == m-1)    return ans;
                
                for(int i=0;i<4;i++){
                    int nx = x+dir[i][0], ny = y+dir[i][1];
                    int nk = ck;
                    if(nx>=0 && nx<n && ny>=0 && ny < m){
                        if(grid[nx][ny] == 1){
                            nk++;
                        }
                        if(nk<=k && !vis[nx][ny][nk]){
                            vis[nx][ny][nk] = true;
                            q.push({nx, ny, nk});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};