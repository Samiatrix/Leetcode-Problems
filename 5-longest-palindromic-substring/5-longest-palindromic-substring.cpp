class Solution {
public:
    pair<int, int> palindrome(string s, int i, int j){
        if(s[i]!=s[j])  return {-1, -1};
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return {i+1, j-i-1};
    }
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        for(int i=0;i<s.size();i++){
            pair<int, int> a = palindrome(s, i, i);
            pair<int, int> b = palindrome(s, i, i+1);
            if(a.second>len){
                ans = s.substr(a.first, a.second);
                len = a.second;
            }
            if(b.second>len){
                ans = s.substr(b.first, b.second);
                len = b.second;
            }
        }
        return ans;
    }
};