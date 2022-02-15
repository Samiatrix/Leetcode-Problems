class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for(auto i:weights){
            l = max(l, i);
            r+=i;
        }
        
        while(l<r){
            int m = l+(r-l)/2;
            int curr = 0, day = 1;
            for(int i=0;i<weights.size() && day<=days;i++){
                if(curr+weights[i]>m){
                    curr = weights[i];
                    day++;
                }
                else{
                    curr+=weights[i];
                }
            }
            
            if(day>days)    l = m+1;
            else    r = m;
        }
        return l;
    }
};