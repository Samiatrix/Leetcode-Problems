class Solution {
public:
    string simplifyPath(string s) {
        string ans="";
        stack<string> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='/'){
                string temp="";
                while(i<s.size() && s[i]!='/'){
                    temp+=s[i];
                    i++;
                }
                if(temp.size() == 2 && temp == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(temp.size() == 1 && temp == "."){
                    
                }
                else if(temp!=""){
                    st.push(temp);
                }
            }
//             if(s[i] == '.' and i+1<s.size() && s[i+1] == '.'){
//                 if(!st.empty()){
//                     st.pop();
                    
//                 }
//             }
//             else if(s[i] == '.'){
//                 continue;
//             }
//             else if(isalpha(s[i])){
//                 string temp="";
//                 while(i<s.size() && isalpha(s[i])){
//                     temp+=s[i];
//                     i++;
//                 }
//                 st.push(temp);
//             }
        }
        while(!st.empty()){
            cout<<st.top()<<endl;
            ans = st.top() + ans;
            ans = '/'+ans;
            st.pop();
        }
        if(ans == ""){
            return "/";
        }
        return ans;
    }
};