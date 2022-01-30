class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(curr);
                curr = "";
            }
            else if(s[i] == ')'){
                reverse(curr.begin(), curr.end());
                if(!st.empty()){
                    string t = st.top();
                    st.pop();
                    t+=curr;
                    curr = t;
                }
            }
            else{
                curr+=s[i];
            }
        }
        return curr;
    }
};