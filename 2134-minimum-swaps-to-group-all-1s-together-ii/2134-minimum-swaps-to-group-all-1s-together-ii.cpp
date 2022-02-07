class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        for(auto i:nums)    count+=(i == 1);
        int ans = 0;
        int curr = 0;
        int n = nums.size();
        for(int i=0;i<n*2;i++){
            if(i>=count && nums[(i - count)%n] == 1)  curr--;
            if(nums[i%n] == 1) curr++;
            ans = max(ans, curr);
        }
        return count-ans;
    }
};