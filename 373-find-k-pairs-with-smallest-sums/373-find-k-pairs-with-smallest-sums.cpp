struct compare{
    bool operator()(vector<int>& a, vector<int>& b){
        return (a[0] + a[1]) > (b[0] + b[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long n = nums1.size(), m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(int i=0;i<nums1.size() && i<k;i++){
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            auto curr = pq.top();
            pq.pop();
            ans.push_back({curr[0], curr[1]});
            if(curr[2] == m-1)  continue;
            pq.push({curr[0], nums2[curr[2]+1], curr[2]+1});
        }
        return ans;
        
    }
};