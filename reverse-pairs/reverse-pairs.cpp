class Solution {
public:
    int merge(vector<int>& nums, int l, int r, vector<int>& temp){
        if(l>=r) return 0;
        int m = l+(r-l)/2;
        int count = merge(nums, l, m, temp)+merge(nums, m+1, r, temp);
        
        for(int i=l, j = m+1;i<=m;i++){
            while(j<=r && (nums[i]/2.0)>nums[j])  j++;
            count+=(j-(m+1));
        }
        int mid = m+1;
        int k=l;
        for(int i=l;i<=r;i++)   temp[i] = nums[i];
        while(l<=m && mid<=r){
            if(temp[l]>temp[mid]){
                nums[k++] = temp[mid++];
            }
            else{
                nums[k++] = temp[l++];
            }
        }
        while(l<=m){
            nums[k++] = temp[l++];
        }
        while(mid<=r){
            nums[k++] = temp[mid++];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return merge(nums, 0, nums.size()-1, temp);
    }
};