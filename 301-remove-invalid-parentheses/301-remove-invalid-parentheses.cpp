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
        queue<pair<string, int>> q;
        q.push({s, 0});
        // unordered_set<string> st;
        vector<string> ans;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            // if(st.count(curr))  continue;
            // st.insert(curr);
            string st = curr.first;
            int ind = curr.second;
            
            if(isValid(st))   ans.push_back(st);
            else if(ans.empty()){
                for(int i=ind;i<st.size();i++){
                    if((st[i] == '(' || st[i] == ')') && (i==ind || st[i-1] != st[i]))    q.push({st.substr(0, i)+st.substr(i+1), i});
                }
            }
        }
        return ans;
    }
};