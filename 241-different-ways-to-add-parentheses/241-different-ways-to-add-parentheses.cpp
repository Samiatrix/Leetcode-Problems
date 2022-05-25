class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> l = diffWaysToCompute(expression.substr(0, i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
                for(int le = 0;le<l.size();le++){
                    for(int ri = 0;ri<r.size();ri++){
                        if(expression[i] == '+'){
                            ans.push_back(l[le] + r[ri]);
                        }
                        else if(expression[i] == '-'){
                            ans.push_back(l[le] - r[ri]);
                        }
                        else if(expression[i] == '*'){
                            ans.push_back(l[le] * r[ri]);
                        }
                    }
                }
            }
        }
        if (ans.empty()){
            // cout<<(expression[0])<<endl;
            // cout<<(atoi(expression.c_str())<<endl;
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};