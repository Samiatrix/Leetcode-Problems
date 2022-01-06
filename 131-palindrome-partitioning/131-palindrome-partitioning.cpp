class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l++]!=s[r--])  return false;
        }
        return true;
    }
    void dfs(string& s, int ind, vector<string>& curr, vector<vector<string>>& ans){
        if(ind >= s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s, ind, i)){
                curr.push_back(s.substr(ind, i-ind+1));
                dfs(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(s, 0, curr, ans);
        return ans;
    }
};