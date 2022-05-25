class Solution {
public:
    bool isValid(string s){
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') count++;
            else if(s[i] == ')'){
                if(count>0) count--;
                else    return false;
            }
        }
        return !count;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vector<string> ans;
        unordered_set<string> st;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(st.count(curr))  continue;
            st.insert(curr);
            if(isValid(curr))   ans.push_back(curr);
            else if(ans.empty()){
                for(int i=0;i<curr.size();i++){
                    if(curr[i] == '(' || curr[i] == ')')  q.push(curr.substr(0, i) + curr.substr(i+1));
                }
            }
        }
        return ans;
    }
};