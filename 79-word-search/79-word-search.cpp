class Solution {
public:
    bool check(vector<vector<char>>& grid, int i, int j, string s, int ind){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=s[ind])  return false;
        if(ind == s.size()-1)   return true;
        char ch = grid[i][j];
        grid[i][j] = '*';
        if(check(grid, i+1, j, s, ind+1))   return true;
        if(check(grid, i-1, j, s, ind+1))   return true;
        if(check(grid, i, j+1, s, ind+1))   return true;
        if(check(grid, i, j-1, s, ind+1))   return true;
        grid[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(check(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};