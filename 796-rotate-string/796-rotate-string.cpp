class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()) return false;
        s+=s;
        return s.find(goal)!=string::npos;
    }
};