class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        for(int i = 2 * nums.size() - 1 ; i >= 0 ; i--){
            while(!s.empty() && s.top() <= nums[ i % n ]){
                s.pop();
            }
            ans[i%n] = (s.empty() ? -1 : s.top());
            s.push(nums[i%n]);
        }
        return ans;
        
    }
};