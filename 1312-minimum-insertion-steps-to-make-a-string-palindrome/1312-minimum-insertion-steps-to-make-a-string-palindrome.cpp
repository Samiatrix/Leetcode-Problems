class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                curr[j] = (s[i-1] == t[j-1]) ? (1 + prev[j-1]) : max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return n-prev[n];
    }
};