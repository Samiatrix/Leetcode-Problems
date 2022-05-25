class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(auto i:s){
            if( (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')){
                s1 += tolower(i);
            }
            else if(i>='0' && i<='9'){
                s1 += i;
            }
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};