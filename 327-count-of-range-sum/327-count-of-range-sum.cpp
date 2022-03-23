class Solution {
public:
    int count(vector<long>& sum, int low, int upp, int l, int r){
        if(r-l<=1)  return 0;
        int mid = l+(r-l)/2;
        int ans = 0, m = mid, n = mid;
        ans = count(sum, low, upp, l, mid) + count(sum, low, upp, mid, r);
        
        for(int i=l;i<mid;i++){
            while(m<r && sum[m]-sum[i] < low)    m++;
            while(n<r && sum[n]-sum[i] <= upp)    n++;
            ans += n-m;
        }
        
        inplace_merge(sum.begin()+l, sum.begin()+mid, sum.begin()+r);
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++)  sum[i+1] = sum[i]+nums[i];
        return count(sum, lower, upper, 0, nums.size()+1);
    }
};