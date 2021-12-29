class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y = 0;
        unordered_set<string> s;
        s.insert(to_string(x)+"#"+to_string(y));
        vector<char> d = {'r', 'u', 'l', 'd'};
        int ind = 0;
        char dir = 'r';
        for(auto i:instructions){
            if(i == 'G'){
                if(dir == 'r')  y++;
                else if(dir == 'l') y--;
                else if(dir == 'u') x--;
                else if(dir == 'd') x++;
            }
            else if(i == 'L'){
                ind++;
                ind%=4;
                dir = d[ind];
            }
            else if(i == 'R'){
                ind+=4;
                ind--;
                ind%=4;
                dir = d[ind];
            }
        }
        return x == 0 && y == 0 || dir != 'r';
    }
};