class Solution {
public:
    int unique(int i, int j, int m, int n, vector<vector<int>>& mem){
        if(i>=m || j>=n)  return 0;
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(mem[i][j]!=-1)   return mem[i][j];
        mem[i][j] = unique(i+1, j, m, n, mem)+unique(i, j+1, m, n, mem);
        return mem[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return unique(0, 0, m, n, mem);
    }
};