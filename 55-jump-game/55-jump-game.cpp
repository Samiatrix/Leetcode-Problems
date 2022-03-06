class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        int curr = 0;
        for(int i=0;i<nums.size() && i<=curr;i++){
            curr = max(curr, i+nums[i]);
            if(curr>=n) return true;
        }
        return false;
    }
};