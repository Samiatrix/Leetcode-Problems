class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long ma = 0;
        long mi = 0;
        long curr = 0;
        for(auto i:differences){
            curr+=i;
            ma = max(ma, curr);
            mi = min(mi, curr);
        }
        long ans = max(0L, (upper-lower)-(ma-mi)+1);
        return ans;
        
    }
};