class Solution {
public:
    int merge(vector<int>& nums, long long l, long long r, vector<long long>& temp){
        if(l>=r) return 0;
        long long m = l+(r-l)/2;
        long long count = merge(nums, l, m, temp) + merge(nums, m+1, r, temp);
        for(long long i=l, j = m+1;i<=m;i++){
            while(j<=r && nums[i]>nums[j])  j++;
            count+=(j-(m+1));
        }
        long long mid = m+1;
        for(long long i=l;i<=r;i++){
            temp[i] = nums[i];
        }
        long long k = l;
        while(l<=m && mid<=r){
            if(temp[l]<=temp[mid]){
                nums[k++] = temp[l++];
            }
            else{
                nums[k++] = temp[mid++];
            }
        }
        while(l<=m) nums[k++] = temp[l++];
        while(mid<=r) nums[k++] = temp[mid++];
        return count;
    }
    bool isIdealPermutation(vector<int>& nums) {
        long long local = 0;
        long long global = 0;
        for(long long i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])   local++;
        }
        vector<long long> temp(nums.size());
        global = merge(nums, 0, nums.size()-1, temp);
        // cout<<local<<", "<<global<<endl;
        return local == global;
    }
};