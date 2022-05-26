class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0], i, 0});
        }
        int ans = -1;
        while(!pq.empty() && k-->1){
            auto curr = pq.top();
            pq.pop();
            if(curr[2]+1<matrix[0].size()){
                pq.push({matrix[curr[1]][curr[2]+1], curr[1], curr[2]+1});
            }
        }
        return pq.top()[0];
        // for(auto i:matrix){
        //     for(auto j:i){
        //         pq.push(j);
        //         if(pq.size()>k) pq.pop();
        //     }
        // }
        // return pq.top();
    }
};