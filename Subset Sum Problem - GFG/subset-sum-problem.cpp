// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool summ(vector<int>& arr, int ind, int tar, vector<vector<int>>& dp){
        if(ind>=arr.size()) return false;
        if(arr[ind] == tar)    return true;
        if(dp[ind][tar]!=-1)    return dp[ind][tar];
        bool notTake = summ(arr, ind+1, tar, dp);
        bool take = false;
        if(tar>=arr[ind])   take = summ(arr, ind+1, tar-arr[ind], dp);
        return dp[ind][tar] = take || notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        return summ(arr, 0, sum, dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends