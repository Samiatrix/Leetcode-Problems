class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, int> ls;
        int n = board.size(), m = board[0].size();
        int ind = 1;
        bool left = true;
        for(int i=n-1;i>=0;i--){
            for(int j= (left) ? 0 : m-1; (left) ? j<m : j>=0 ; (left) ? j++ : j--){
                if(board[i][j] != -1){
                    ls[ind] = board[i][j];
                }
                ind++;
            }
            left = !left;
        }
        unordered_set<int> vis;
        queue<int> q;
        q.push(1);
        vis.insert(1);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                if(curr == (n*m))   return ans;
                
                for(int i=1;i<=6;i++){
                    int ni = curr + i;
                    if(ls.count(ni)){
                        ni = ls[ni];
                    }
                    if(ni<=(n*m) && !vis.count(ni)){
                        vis.insert(ni);
                        q.push(ni);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};