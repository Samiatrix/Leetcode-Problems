class Solution {
public:
    void merge(vector<pair<int, int>>& nums, int l, int r, vector<int>& ans){
        if(l>=r)    return;
        int mid = (l+r)/2;
        merge(nums, l, mid, ans);
        merge(nums, mid+1, r, ans);
        
        int left = l;
        int right = mid+1;
        vector<pair<int, int>> merged;
        int elementGreaterThanLeft = 0;
        while(left<mid+1 && right<=r){
            if(nums[left].first>nums[right].first){
                elementGreaterThanLeft++;
                merged.push_back(nums[right]);
                right++;
            }
            else{
                ans[nums[left].second]+=elementGreaterThanLeft;
                merged.push_back(nums[left]);
                left++;
            }
        }
        
        while(left<mid+1){
            ans[nums[left].second]+=elementGreaterThanLeft;
            merged.push_back(nums[left]);
            left++;
        }
        
        while(right<=r){
            // ans[nums[left].second]+=elementGreaterThanLeft;
            merged.push_back(nums[right]);
            right++;
        }
        int i = l;
        for(auto j:merged){
            nums[i] = j;
            i++;
        }
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        vector<pair<int, int>> t;
        for(int i=0;i<nums.size();i++){
            t.push_back({nums[i], i});
        }
        vector<int> ans(nums.size(), 0);
        merge(t, l, r, ans);
        return ans;
    }
};