class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                while(!s.empty() && s.top()<=nums2[i])  s.pop();
                mp[nums2[i]] = s.empty() ? -1 : s.top();
            }
            
                s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};