class Solution {
public:
    string palindrome(string s, int l, int r){
        if(s[l]!=s[r])  return "";
        while(l>=0 && r<s.size() && s[l] == s[r]){
            // cout<<l<<" "<<r<<endl;
            l--;
            r++;
        }
        // cout<<"final"<<l<<" "<<r<<endl;
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string ans = "";
        int g = 0;
        for(int i=0;i<s.size();i++){
            string a = palindrome(s, i, i);
            // cout<<a<<endl;
            string b = palindrome(s, i, i+1);
            // cout<<a<<" "<<b<<endl;
            if(a.size()>g){
                ans = a;
                g = a.size();
            }
            if(b.size()>g){
                ans = b;
                g = b.size();
            }
            // ans = max({ans, a,b});
        }
        return ans;
    }
};