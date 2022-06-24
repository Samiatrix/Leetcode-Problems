class Solution {
public:
    bool find(string& word, vector<vector<char>>& board, int i, int j, int ind){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[ind])   return false;
        if(ind == word.size()-1)    return true;
        
        char ch = board[i][j];
        board[i][j] = '*';
        
        bool ans = find(word, board, i+1, j, ind+1) || find(word, board, i-1, j, ind+1) || find(word, board, i, j+1, ind+1) || find(word, board, i, j-1, ind+1);
        board[i][j] = ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(word[0] == board[i][j]){
                    if(find(word, board, i, j, 0))  return true;
                }
            }
        }
        return false;
    }
};