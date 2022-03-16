class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int maxi = values[0]-1;
        for(int i=1;i<values.size();i++){
            // cout<<maxi<<" "<<last<<" "<<values[i]<<" "<<i<<endl;
            ans = max(ans, values[i]+maxi);
            maxi = max(maxi, values[i])-1;
            
            
            
//             for(int j=i+1;j<values.size();j++){
//                 ans = max(ans, values[i]+values[j]+i-j);
//             }
        }
        return ans;
    }
};