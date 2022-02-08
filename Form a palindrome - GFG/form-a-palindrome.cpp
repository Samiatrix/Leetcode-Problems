// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int count(string s, int l, int r, vector<vector<int>>& dp){
        if(l>r) 1e8;
        
        if(l == r)  return 0;
        if(l == r-1){
            return s[l] == s[r] ? 0 : 1;
        }
        if(dp[l][r]!=-1)    return dp[l][r];
        return dp[l][r] = s[l] == s[r] ? count(s, l+1, r-1, dp) : 1+min(count(s, l+1, r, dp), count(s, l, r-1, dp));
    }
    int countMin(string str){
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return count(str, 0, n-1, dp);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends