class Solution {
public:
    
    void merge(vector<pair<int, int>>& nums, int l, int r, vector<int>& ans){
        if(l>=r)    return;
        
        int mid = l+(r-l)/2;
        merge(nums, l, mid, ans);
        merge(nums, mid+1, r, ans);
        
        int left = l;
        int right = mid+1;
        int numbersSmallerThanLeft = 0;
        
        vector<pair<int, int>> merged;
        
        while(left<=mid && right<=r){
            if(nums[left].first > nums[right].first){
                numbersSmallerThanLeft++;
                merged.push_back(nums[right++]);
            }
            else{
                ans[nums[left].second]+=numbersSmallerThanLeft;
                merged.push_back(nums[left++]);
            }
        }
        
        while(left<=mid){
            ans[nums[left].second]+=numbersSmallerThanLeft;
            merged.push_back(nums[left++]);
        }
        
        while(right<=r){
            merged.push_back(nums[right++]);
        }
        
        
        int pos = l;
        for(auto i:merged){
            nums[pos++] = i;
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> numi;
        for(int i=0;i<nums.size();i++){
            numi.push_back({nums[i], i});
        }
        
        vector<int> ans(nums.size(), 0);
        
        merge(numi, 0, nums.size()-1, ans);
        
        return ans;
    }
};