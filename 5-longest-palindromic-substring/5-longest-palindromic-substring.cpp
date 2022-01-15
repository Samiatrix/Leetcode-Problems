class Solution {
public:
    pair<int, int> palindrome(string s, int l, int r){
        // if(s[l]!=s[r])  return {0, 0};
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return {l+1, r-l-1};
    }
    string longestPalindrome(string s) {
        int l = 0;
        int len = 0;
        for(int i=0;i<s.size();i++){
            auto a = palindrome(s, i, i);
            auto b = palindrome(s, i, i+1);
            if(a.second>len){
                len = a.second;
                l = a.first;
            }
            if(b.second>len){
                len = b.second;
                l = b.first;
            }
        }
        return s.substr(l, len);
    }
};