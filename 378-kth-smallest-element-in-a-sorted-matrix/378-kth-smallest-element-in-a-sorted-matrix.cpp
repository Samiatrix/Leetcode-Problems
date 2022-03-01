class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() * matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto r:matrix){
            for(auto i:r){
                pq.push(i);
                if(pq.size()>(n-k+1))   pq.pop();
            }
        }
        return pq.top();
    }
};