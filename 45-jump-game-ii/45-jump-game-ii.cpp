class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, ans = 0, curr_end = 0;
        for(int i=0;i<nums.size()-1;i++){
            curr = max(curr, i+nums[i]);
            if(curr_end == i){
                ans++;
                curr_end = curr;
            }
        }
        return ans;
    }
};