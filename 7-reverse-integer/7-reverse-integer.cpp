class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool neg = false;
        if(s[0] == '-') neg = true;
        if(neg) s = s.substr(1);
        std::reverse(s.begin(), s.end());
        long ans = stol(s);
        if(ans<INT_MIN || ans>INT_MAX)  return 0;
        return neg ? -1*ans : ans;
        return 0;
    }
};