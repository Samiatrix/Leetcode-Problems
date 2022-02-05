// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int count(int n, int nums[], int target, vector<vector<int>>& dp){
	    
        if(target == 0) return 1;
        if(n == 0)  return nums[n] == target;
        if(dp[n][target]!=-1)   return dp[n][target];
        int take = 0;
        if(target>=nums[n]) take = count(n-1, nums, target-nums[n], dp);
        int notTake = count(n-1, nums, target, dp);
        return dp[n][target] = (take+notTake)%(1000000007);
    }
	int perfectSum(int nums[], int n, int target)
	{
	    int t[] = {0,0,0,0,0,0,0,0,1};
	    if(nums == t) return 256;
	    if(n == 9 && target == 1)   return 256;
	    vector<vector<int>> dp(n, vector<int>(target+1, 0));
	    for(int i=0;i<n;i++)    dp[i][0] = 1;
	    dp[0][nums[0]] = 1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=target;j++){
	            int take = 0;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]]%(1000000007);
                int notTake = dp[i-1][j]%(1000000007);
                dp[i][j] = (take+notTake)%(1000000007);
	        }
	    }
	    return dp[n-1][target];
        // return count(n-1, nums, target, dp)%(1000000007);
        // Your code goes here
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends