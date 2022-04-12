class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        vector<vector<int>> next = board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int one = 0, zero = 0;
                for(auto curr:dir){
                    int x = curr.first+i;
                    int y = curr.second+j;
                    if(x>=0 && x<board.size() && y>=0 && y<board[0].size()){
                        if(board[x][y] == 0)    zero++;
                        else    one++;
                    }
                }
                if(board[i][j] == 1){
                    if(one<2)   next[i][j] = 0;
                    else if(one == 2 || one == 3)   next[i][j] = 1;
                    else if(one > 3)    next[i][j] = 0;
                }
                else if(board[i][j] == 0){
                    if(one == 3)    next[i][j] = 1;
                }
            }
        }
        
            board = next;
    }
};