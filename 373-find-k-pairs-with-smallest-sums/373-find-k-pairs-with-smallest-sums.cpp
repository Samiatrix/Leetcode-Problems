struct compare{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[2] > b[2];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long n = nums1.size(), m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(int j=0;j<nums2.size();j++){
            pq.push({0, j, nums1[0]+nums2[j]});
        }
        vector<vector<int>> ans;
        long len = n*m;
        for(long long i=0;i<min((long)k, len);i++){
            auto curr = pq.top();
            pq.pop();
            ans.push_back({nums1[curr[0]], nums2[curr[1]]});
            if(curr[0] == n-1)  continue;
            pq.push({curr[0]+1, curr[1], nums1[curr[0]+1]+nums2[curr[1]]});
        }
        return ans;
        
    }
};