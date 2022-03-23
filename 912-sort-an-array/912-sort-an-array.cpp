class Solution {
public:
    void merge(int l, int r, vector<int>& nums){
        if(l>=r)    return;
        int mid = l+(r-l)/2;
        merge(l, mid, nums);
        merge(mid+1, r, nums);
        
        vector<int> t;
        int left = l;
        int right = mid+1;
        while(left<=mid && right<=r){
            if(nums[left]<nums[right]){
                t.push_back(nums[left++]);
            }
            else{
                t.push_back(nums[right++]);
            }
        }
        
        while(left<=mid)    t.push_back(nums[left++]);
        while(right<=r)    t.push_back(nums[right++]);
        
        
        int pos = l;
        for(auto i:t){
            nums[pos] = i;
            pos++;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        merge(l, r, nums);
        return nums;
        
    }
};