class Solution {
public:
    int count(vector<long>& sum, int lower, int upper, int l, int r){
        if(r-l<=1)  return 0;
        
        int mid = l+(r-l)/2;
        
        int ans = 0;
        int le = count(sum, lower, upper, l, mid);
        int ri = count(sum, lower, upper, mid, r);
        ans = le+ri;
        
        int m = mid, n = mid;
        for(int i=l;i<mid;i++){
            while(m<r && sum[m]-sum[i] < lower) m++;
            while(n<r && sum[n]-sum[i] <= upper) n++;
            ans+=(n-m);
        }
        
        inplace_merge(sum.begin()+l, sum.begin()+mid, sum.begin()+r);
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n+1, 0);
        for(long i=0;i<n;i++)    sum[i+1] = sum[i]+nums[i];
        return count(sum, lower, upper, 0, n+1);
    }
};