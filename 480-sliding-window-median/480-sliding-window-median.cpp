class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> ms(nums.begin(), nums.begin()+k);
        auto mid = next(ms.begin(), k/2);
        vector<double> ans;
        for(int i=k;true;i++){
            auto previous = prev(mid, 1-k%2);
            double median = (*mid + *previous)/2.0;
            ans.push_back(median);
            
            if(i == nums.size())    return ans;
            ms.insert(nums[i]);
            
            if(nums[i] < *mid){
                mid--;
            }
            
            if(nums[i-k] <= *mid){
                mid++;
            }
            ms.erase(lower_bound(ms.begin(), ms.end(), nums[i-k]));
        }
        return ans;
    }
};