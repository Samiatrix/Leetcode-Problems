class Solution {
public:
    vector<string> ans;
    void word(string s, unordered_set<string>& st, int ind, string curr){
        if(ind>=s.size()){
            ans.push_back(curr.substr(0, curr.size()-1));
            return;
        }
        string t = "";
        for(int i=ind;i<s.size();i++){
            t+=s[i];
            if(st.count(t)) word(s, st, i+1, curr+t+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        string curr = "";
        word(s, st, 0, curr);
        return ans;
    }
};