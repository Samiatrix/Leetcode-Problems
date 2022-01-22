class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long ma = LONG_MIN;
        long mi = LONG_MAX;
        long curr = 0;
        for(auto i:differences){
            curr+=i;
            ma = max(ma, curr);
            mi = min(mi, curr);
        }
        int ans = 0;
        for(int i=lower;i<=upper;i++){
            if(ma+i<=upper && mi+i>=lower)  ans++;
        }
        return ans;
        
    }
};