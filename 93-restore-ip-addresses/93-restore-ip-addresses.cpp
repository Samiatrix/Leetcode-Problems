class Solution {
public:
    void restore(string& s, int ind, int level, string curr, vector<string>& ans){
        if(level == 4 && ind>=s.size()){
            ans.push_back(curr.substr(0, curr.size()-1));
        }
        int n = 0;
        for(int i=ind;i<ind+3 && i<s.size();i++){
            n = n*10 + (s[i]-'0');
            if(n <= 255){
                restore(s, i+1, level+1, curr+to_string(n)+".", ans);
            }
            if(n == 0)  break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string curr = "";
        vector<string> ans;
        restore(s, 0, 0, curr, ans);
        return ans;
    }
};