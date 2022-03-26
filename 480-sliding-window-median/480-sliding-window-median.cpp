class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.begin()+k);
        auto mid = next(ms.begin(), k/2);
        vector<double> ans;
        int i = k;
        while(true){
            auto previous = prev(mid, 1-k%2);
            ans.push_back(((double)*mid + (double)*previous)/2.0);
            if(i == nums.size())    return ans;
            ms.insert(nums[i]);
            
            if(nums[i] < *mid){
                mid--;
            }
            
            if(nums[i-k] <= *mid){
                mid++;
            }
            ms.erase(lower_bound(ms.begin(), ms.end(), nums[i-k]));
            
            i++;
        }
        return ans;
    }
};