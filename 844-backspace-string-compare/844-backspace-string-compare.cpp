class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a = 0, b = 0;
        int n = s.size()-1, m = t.size()-1;
        while(n >= 0 || m >= 0){
            while(n >= 0){
                if(s[n] == '#'){
                    a++;
                    n--;
                }
                else if(a>0){
                    a--;
                    n--;
                }
                else    break;
            }
            while(m >= 0){
                if(t[m] == '#'){
                    b++;
                    m--;
                }
                else if(b>0){
                    b--;
                    m--;
                }
                else    break;
            }
            
            if(n>=0 && m>=0 && s[n]!=t[m]){
                return false;
            }
            if((n>=0)!=(m>=0))  return false;
            n--;
            m--;
        }
        return true;
    }
};