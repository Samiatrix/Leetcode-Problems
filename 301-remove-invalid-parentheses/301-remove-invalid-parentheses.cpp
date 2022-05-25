class Solution {
public:
    bool isValid(string s){
        int count = 0;
        for(auto i:s){
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
        vector<string> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string curr = p.first;
            int ind = p.second;
            if(isValid(curr)){
                ans.push_back(curr);
            }
            else if(ans.empty()){
                for(int i=ind;i<curr.size();i++){
                    if((curr[i] == '(' || curr[i] == ')') && (i == ind || curr[i]!=curr[i-1])){
                        q.push({curr.substr(0, i) + curr.substr(i+1), i});
                    }
                }
            }
        }
        return ans;
    }
};