class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans=0,m=1;
        for(int i=0;S[i]!='\0';i++){
            if(S[i]=='('){
                if(S[i+1]==')'){
                    ans=ans+m;
                    i++;
                }
                else{
                    m=m*2;
                }
            }
            else{
                m=m/2;
            }
        }
        return ans;
    }
};