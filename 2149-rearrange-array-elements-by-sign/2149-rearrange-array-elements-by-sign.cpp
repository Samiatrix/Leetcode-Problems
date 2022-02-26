class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto i:nums){
            if(i>=0) pos.push_back(i);
            else    neg.push_back(i);
        }
        for(int i=0, j=0;i<nums.size();i+=2, j++){
            nums[i] = pos[j];
            nums[i+1] = neg[j];
        }
        return nums;
    }
};