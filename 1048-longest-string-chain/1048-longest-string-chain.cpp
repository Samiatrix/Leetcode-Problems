class Solution {
public:
    unordered_map<string, int> dp;
    int dfs(string& s, unordered_set<string>& st){
        if(dp.count(s)) return dp[s];
        
        int count = 0;
        for(int i=0;i<s.size();i++){
            string curr = s.substr(0, i) + s.substr(i+1);
            if(st.count(curr)){
                count = max(count, dfs(curr, st));
            }
        }
        dp[s] = count+1;
        return count+1;
    }
    int longestStrChain(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        int ans = 0;
        for(auto s: words){
            ans = max(ans, dfs(s, st));
        }
        return ans;
    }
};