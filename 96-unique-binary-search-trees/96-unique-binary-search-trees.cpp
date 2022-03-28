class Solution {
public:
    int tree(int n, vector<int>& dp){
        if(n == 0 || n == 1)  return 1;
        if(dp[n]!=-1)   return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += tree(i-1, dp) * tree(n-i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return tree(n, dp);
    }
};