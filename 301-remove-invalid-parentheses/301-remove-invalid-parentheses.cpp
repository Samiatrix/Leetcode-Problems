class Solution {
public:
    bool isValid(string curr){
        int count = 0;
        for(auto i:curr){
            if(i == '(')    count++;
            else if(i == ')'){
                if(count>0) count--;
                else    return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        unordered_set<string> st;
        vector<string> ans;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(st.count(curr))  continue;
            st.insert(curr);
            if(isValid(curr))   ans.push_back(curr);
            else if(ans.empty()){
                for(int i=0;i<curr.size();i++){
                    if(curr[i] == '(' || curr[i] == ')')    q.push(curr.substr(0, i)+curr.substr(i+1));
                }
            }
        }
        return ans;
    }
};