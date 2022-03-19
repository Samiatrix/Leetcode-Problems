class Solution {
public:
    pair<int, int> pal(string& s, int l, int r){
        if(s[l]!=s[r])  return {0, 0};
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return {l+1, r-l-1};
    }
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        for(int i=0;i<s.size();i++){
            pair<int, int> s1 = pal(s, i, i);
            pair<int, int> s2 = pal(s, i, i+1);
            if(len<s1.second){
                len = s1.second;
                ans = s.substr(s1.first, len);
            }
            if(len<s2.second){
                len = s2.second;
                ans = s.substr(s2.first, len);
            }
        }
        return ans;
    }
};