// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void subset(vector<int>& arr, int n, int ind, vector<int>& ans, int curr){
        if(ind == n){
            ans.push_back(curr);
            return ;
        }
        subset(arr, n, ind+1, ans, curr);
        subset(arr, n, ind+1, ans, curr+arr[ind]);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subset(arr, N, 0, ans, 0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends