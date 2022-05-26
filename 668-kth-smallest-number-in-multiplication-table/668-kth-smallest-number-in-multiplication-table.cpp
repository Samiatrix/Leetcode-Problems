class Solution {
public:
    int countLessThanOrEqualToMid(int& n, int& m, int mid){
        int count = 0;
        for(int i=1;i<=n;i++){
            count += min((mid/i), m);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(countLessThanOrEqualToMid(m, n, mid)>=k){
                ans = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }
        return ans;
    }
};