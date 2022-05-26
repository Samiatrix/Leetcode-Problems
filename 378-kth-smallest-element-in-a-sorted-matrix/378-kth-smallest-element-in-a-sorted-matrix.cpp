class Solution {
public:
    int countLessThanOrEqualToMid(vector<vector<int>>& matrix, int mid){
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = m-1;
            while(j>=0 && matrix[i][j] > mid){
                j--;
            }
            ans+=(j+1);
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n-1][m-1];
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(countLessThanOrEqualToMid(matrix, mid) >= k){
                ans = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }
        return ans;
        
        // priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        // for(int i=0;i<matrix.size();i++){
        //     pq.push({matrix[i][0], i, 0});
        // }
        // int ans = -1;
        // while(!pq.empty() && k-->1){
        //     auto curr = pq.top();
        //     pq.pop();
        //     if(curr[2]+1<matrix[0].size()){
        //         pq.push({matrix[curr[1]][curr[2]+1], curr[1], curr[2]+1});
        //     }
        // }
        // return pq.top()[0];
        // for(auto i:matrix){
        //     for(auto j:i){
        //         pq.push(j);
        //         if(pq.size()>k) pq.pop();
        //     }
        // }
        // return pq.top();
    }
};