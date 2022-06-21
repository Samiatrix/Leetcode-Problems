class Solution {
public:
    unordered_map<string, int> mp;
    int dfs(string& s, unordered_set<string>& st){
        if(mp.count(s)) return mp[s];
        int count = 0;
        for(int i=0;i<s.size();i++){
            string curr = s.substr(0, i) + s.substr(i+1);
            if(st.count(curr))  count = max(count, dfs(curr, st));
        }
        mp[s] = count+1;
        return mp[s];
    }
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        unordered_set<string> st(words.begin(), words.end());
        for(auto s:words){
            ans = max(ans, dfs(s, st));
        }
        return ans;
    }
};