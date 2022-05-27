class Solution {
public:
    bool find(vector<vector<char>>& mat, int i, int j, string word, int ind){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size()) return false;
        if(word[ind]!=mat[i][j])    return false;
        if(ind == word.size()-1)  return true;
        char ch = mat[i][j];
        mat[i][j] = '*';
        bool f = find(mat, i+1, j, word, ind+1) || find(mat, i-1, j, word, ind+1) || find(mat, i, j+1, word, ind+1) || find(mat, i, j-1, word, ind+1);
        mat[i][j] = ch;
        return f;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(find(board, i, j, word, 0))  return true;
                }
            }
        }
        return false;
    }
};