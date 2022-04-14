class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> leftIndex;
        unordered_map<int, int> rightIndex;
        unordered_map<int, int> count;
        int degree = 0;
        for(int i=0;i<nums.size();i++){
            if(leftIndex.count(nums[i]) == 0)   leftIndex[nums[i]] = i;
            rightIndex[nums[i]] = i;
            count[nums[i]]++;
            degree = max(degree, count[nums[i]]);
        }
        int ans = nums.size();
        for(auto curr:count){
            if(curr.second == degree){
                ans = min(ans, rightIndex[curr.first]-leftIndex[curr.first]+1);
            }
        }
        return ans;
    }
};